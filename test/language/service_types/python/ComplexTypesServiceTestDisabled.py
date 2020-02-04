import unittest
from concurrent import futures
import grpc

from testutils import getZserioApi

def _convertRgbToCmyk(rgb):
    # see https://www.rapidtables.com/convert/color/rgb-to-cmyk.html
    rr = rgb[0] / 255. * 100
    gg = rgb[1] / 255. * 100
    bb = rgb[2] / 255. * 100

    k = 100. - max(rr, gg, bb)

    c = round((100. - rr - k) / (100. - k) * 100)
    m = round((100. - gg - k) / (100. - k) * 100)
    y = round((100. - bb - k) / (100. - k) * 100)
    k = round(k)
    return (c, m, y, k)

def _convertCmykToRgb(cmyk):
    # see https://www.rapidtables.com/convert/color/cmyk-to-rgb.html
    r = round(255 * (1 - cmyk[0] / 100.) * (1 - cmyk[3] / 100.))
    g = round(255 * (1 - cmyk[1] / 100.) * (1 - cmyk[3] / 100.))
    b = round(255 * (1 - cmyk[2] / 100.) * (1 - cmyk[3] / 100.))
    return (r, g, b)

RGB_VALUES = [(0, 128, 255), (222, 222, 0), (65, 196, 31)]
CMYK_VALUES = [
    _convertRgbToCmyk(RGB_VALUES[0]),
    _convertRgbToCmyk(RGB_VALUES[1]),
    _convertRgbToCmyk(RGB_VALUES[2])
]

class ComplexTypesServiceTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "service_types.zs").complex_types_service

        class Client:
            def __init__(self, channel):
                self._stub = cls.api.ComplexTypesService.ComplexTypesServiceStub(channel)

            def swapModels(self, request):
                response = self._stub.swapModels(request)
                return response

            def getLength(self, request):
                length = self._stub.getLength(request)
                return length.getLength()

        class Service(cls.api.ComplexTypesService.ComplexTypesServiceServicer):
            def swapModels(self, request, _context):
                requestData = request.getData()
                data = requestData.getData()

                response = cls.api.Response()
                response.setLength(len(data))
                response.setData(cls.api.ResponseData(len(data)))

                if requestData.getModel() == cls.api.ColorModel.RGB:
                    self._rgbToCmyk(data, response)
                else:
                    self._cmykToRgb(data, response)

                return response

            @staticmethod
            def getLength(request, _context):
                requestData = request.getData()
                lengthResponse = cls.api.LengthResponse.fromFields(len(requestData.getData()))
                return lengthResponse

            @staticmethod
            def _rgbToCmyk(data, response):
                cmykData = []
                for element in data:
                    rgbModel = element.getRgb()
                    rgb = (rgbModel.getRed(), rgbModel.getGreen(), rgbModel.getBlue())
                    cmyk = _convertRgbToCmyk(rgb)
                    cmykModel = cls.api.CMYKModel.fromFields(cmyk[0], cmyk[1], cmyk[2], cmyk[3])
                    cmykData.append(cmykModel)
                response.getData().setCmykData(cmykData)

            @staticmethod
            def _cmykToRgb(data, response):
                rgbData = []
                for element in data:
                    cmykModel = element.getCmyk()
                    cmyk = (cmykModel.getCyan(), cmykModel.getMagenta(), cmykModel.getYellow(),
                            cmykModel.getKey())
                    rgb = _convertCmykToRgb(cmyk)
                    rgbModel = cls.api.RGBModel.fromFields(rgb[0], rgb[1], rgb[2])
                    rgbData.append(rgbModel)
                response.getData().setRgbData(rgbData)

        cls.Client = Client
        cls.Service = Service

    def setUp(self):
        self.server = grpc.server(futures.ThreadPoolExecutor())
        self.api.ComplexTypesService.add_ComplexTypesServiceServicer_to_server(self.Service(), self.server)
        port = self.server.add_insecure_port("localhost:0") # 0 to choose port automatically
        self.server.start()
        self.client = self.Client(grpc.insecure_channel("localhost:%d" % port))

    def tearDown(self):
        self.server.stop(0)
        self.server = None
        self.client = None

    def testRgbToCmyk(self):
        length = 10000
        offsets = [0] * length
        data = []
        for i in range(length):
            choice = self.api.ColorModelChoice(self.api.ColorModel.RGB)
            choice.setRgb(self.api.RGBModel.fromFields(RGB_VALUES[i % 3][0],
                                                       RGB_VALUES[i % 3][1],
                                                       RGB_VALUES[i % 3][2]))
            data.append(choice)

        requestData = self.api.RequestData.fromFields(self.api.ColorModel.RGB, offsets, data)
        request = self.api.Request.fromFields(self.api.ColorModel.RGB, requestData)

        self.assertEqual(length, self.client.getLength(request))

        response = self.client.swapModels(request)
        self.assertEqual(length, response.getLength())

        cmykData = response.getData().getCmykData()
        for i, cmyk in enumerate(cmykData):
            self.assertEqual(CMYK_VALUES[i % 3][0], cmyk.getCyan())
            self.assertEqual(CMYK_VALUES[i % 3][1], cmyk.getMagenta())
            self.assertEqual(CMYK_VALUES[i % 3][2], cmyk.getYellow())
            self.assertEqual(CMYK_VALUES[i % 3][3], cmyk.getKey())

    def testCmykToRgb(self):
        length = 10000
        offsets = [0] * length
        data = []
        for i in range(length):
            choice = self.api.ColorModelChoice(self.api.ColorModel.CMYK)
            choice.setCmyk(self.api.CMYKModel.fromFields(CMYK_VALUES[i % 3][0],
                                                         CMYK_VALUES[i % 3][1],
                                                         CMYK_VALUES[i % 3][2],
                                                         CMYK_VALUES[i % 3][3]))
            data.append(choice)

        requestData = self.api.RequestData.fromFields(self.api.ColorModel.CMYK, offsets, data)
        request = self.api.Request.fromFields(self.api.ColorModel.CMYK, requestData)

        self.assertEqual(length, self.client.getLength(request))

        response = self.client.swapModels(request)
        self.assertEqual(length, response.getLength())

        rgbData = response.getData().getRgbData()
        for i, rgb in enumerate(rgbData):
            self.assertEqual(RGB_VALUES[i % 3][0], rgb.getRed())
            self.assertEqual(RGB_VALUES[i % 3][1], rgb.getGreen())
            self.assertEqual(RGB_VALUES[i % 3][2], rgb.getBlue())
