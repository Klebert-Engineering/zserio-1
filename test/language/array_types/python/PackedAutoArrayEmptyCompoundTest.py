import unittest
import os
import zserio

from testutils import getZserioApi, getApiDir

class PackedAutoArrayEmptyCompoundTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "array_types.zs").packed_auto_array_empty_compounds

    def testWriteReadFile(self):
        packedAutoArray = self.api.PackedAutoArray(
            [self.api.EmptyStruct(), self.api.EmptyStruct(), self.api.EmptyStruct()],
            [self.api.EmptyUnion(), self.api.EmptyUnion(), self.api.EmptyUnion()],
            [self.api.EmptyChoice(0), self.api.EmptyChoice(0), self.api.EmptyChoice(0)],
            [
                self.api.Main(self.api.EmptyStruct(), self.api.EmptyUnion(), 0, self.api.EmptyChoice(0)),
                self.api.Main(self.api.EmptyStruct(), self.api.EmptyUnion(), 1, self.api.EmptyChoice(1)),
                self.api.Main(self.api.EmptyStruct(), self.api.EmptyUnion(), 2, self.api.EmptyChoice(2))
            ]
        )

        zserio.serialize_to_file(packedAutoArray, self.BLOB_NAME)
        readPackedAutoArray = zserio.deserialize_from_file(self.api.PackedAutoArray, self.BLOB_NAME)
        self.assertEqual(packedAutoArray, readPackedAutoArray)

    BLOB_NAME = os.path.join(getApiDir(os.path.dirname(__file__)), "packed_auto_array_empty_compounds.blob")
