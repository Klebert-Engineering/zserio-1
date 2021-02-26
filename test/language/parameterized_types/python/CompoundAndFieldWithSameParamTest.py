import unittest
import zserio

from testutils import getZserioApi

# this test is mainly for C++, so just check that it compiles ok
class CompoundAndFieldWithSameParamTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "parameterized_types.zs").compound_and_field_with_same_param

    def testFromReader(self):
        writer = zserio.BitStreamWriter()
        self._writeItemToStream(writer)

        reader = zserio.BitStreamReader(writer.getByteArray(), writer.getBitPosition())
        compound = self.api.Compound.fromReader(reader, self.PARAM)
        self.assertEqual(self.FIELD1, compound.field1.value)
        self.assertEqual(self.FIELD2, compound.field2.value)

        reader = zserio.BitStreamReader(writer.getByteArray(), writer.getBitPosition())
        sameParamTest = self.api.SameParamTest.fromReader(reader)
        self.assertEqual(self.PARAM, sameParamTest.compound.param)
        self.assertEqual(self.FIELD1, sameParamTest.compound.field1.value)
        self.assertEqual(self.FIELD2, sameParamTest.compound.field2.value)

    def _writeItemToStream(self, writer):
        writer.writeBits(self.FIELD1, 32)
        writer.writeBits(self.FIELD2, 32)

    PARAM = 10
    FIELD1 = 1
    FIELD2 = 9
