import unittest

from testutils import getZserioApi

class StructureSubtypeTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.api = getZserioApi(__file__, "subtypes.zs").structure_subtype

    def testSubtype(self):
        identifier = 0xFFFF
        name = "Name"
        student = self.api.Student()
        student.identifier = identifier
        student.name = name

        subtypeStructure = self.api.SubtypeStructure()
        subtypeStructure.student = student
        readStudent = subtypeStructure.student

        self.assertEqual(student, readStudent)
