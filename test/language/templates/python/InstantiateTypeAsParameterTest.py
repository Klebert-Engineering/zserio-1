import unittest
import zserio

from testutils import getZserioApi

class InstantiateTypeAsParameterTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "templates.zs").instantiate_type_as_parameter

    def testReadWrite(self):
        param = self.api.P32.fromFields(2)
        instantiateTypeAsParameter = self.api.InstantiateTypeAsParameter.fromFields(
            param, self.api.Parameterized_P32.fromFields(param, [13, 42])
        )

        writer = zserio.BitStreamWriter()
        instantiateTypeAsParameter.write(writer)
        reader = zserio.BitStreamReader(writer.getByteArray())
        readInstantiateTypeAsParameter = self.api.InstantiateTypeAsParameter()
        readInstantiateTypeAsParameter.read(reader)
        self.assertEqual(instantiateTypeAsParameter, readInstantiateTypeAsParameter)
