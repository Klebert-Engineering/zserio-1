import unittest
import os
import zserio

from testutils import getZserioApi, getApiDir

class PackedAutoArrayUnionHasNoPackableFieldTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "array_types.zs").packed_auto_array_union_has_no_packable_field

    def testWriteRead(self):
        packedAutoArrayUnionHasNoPackableField = self.api.PackedAutoArrayUnionHasNoPackableField(
            [
                self.api.StructWithPackable("A", 65),
                self.api.StructWithPackable("B", 66),
                self.api.StructWithPackable("C", 67)
            ],
            [
                self.api.StructWithPackableArray("ABC", [65, 66, 67]),
                self.api.StructWithPackableArray("DEF", [68, 69, 70]),
                self.api.StructWithPackableArray("GHI", [71, 72, 73])
            ],
            [
                self.api.UnionWithoutPackableField(),
                self.api.UnionWithoutPackableField(),
                self.api.UnionWithoutPackableField()
            ]
        )
        packedAutoArrayUnionHasNoPackableField.array3[0].field1 = 4.0
        packedAutoArrayUnionHasNoPackableField.array3[1].field1 = 1.0
        packedAutoArrayUnionHasNoPackableField.array3[2].field1 = 0.0

        zserio.serialize_to_file(packedAutoArrayUnionHasNoPackableField, self.BLOB_NAME)
        readPackedAutoArrayUnionHasNoPackableField = zserio.deserialize_from_file(
            self.api.PackedAutoArrayUnionHasNoPackableField, self.BLOB_NAME
        )
        self.assertEqual(packedAutoArrayUnionHasNoPackableField, readPackedAutoArrayUnionHasNoPackableField)

    BLOB_NAME = os.path.join(getApiDir(os.path.dirname(__file__)),
                             "packed_auto_array_union_has_no_packable_field.blob")
