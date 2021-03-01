import unittest

from testutils import getZserioApi

class ChoiceWithArrayTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "choice_types.zs").choice_with_array

    def testArray8(self):
        testChoice = self.api.TestChoice(8)
        testChoice.array8 = [self.api.Data8(), self.api.Data8(), self.api.Data8(), self.api.Data8()]
        self.assertEqual(4, len(testChoice.array8))

    def testArray16(self):
        testChoice = self.api.TestChoice(16)
        testChoice.array16 = [1, 2, 3, 4]
        self.assertEqual(4, len(testChoice.array16))
