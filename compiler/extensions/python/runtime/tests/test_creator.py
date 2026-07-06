import unittest

from test_object.api import CreatorEnum, CreatorBitmask, CreatorObject

from zserio.exception import PythonRuntimeException
from zserio.creator import ZserioTreeCreator
from zserio.bitbuffer import BitBuffer
from zserio.typeinfo import TypeInfo, MemberInfo, TypeAttribute, MemberAttribute


class ZserioTreeCreatorTest(unittest.TestCase):

    def test_create_object(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())
        creator.begin_root()
        obj = creator.end_root()
        self.assertTrue(isinstance(obj, CreatorObject))

    def test_create_object_set_fields(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())

        creator.begin_root()
        creator.set_value("value", 13)
        creator.set_value("text", "test")
        obj = creator.end_root()

        self.assertEqual(13, obj.value)
        self.assertEqual("test", obj.text)

    def test_create_object_full(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())

        creator.begin_root()
        creator.set_value("value", 13)
        creator.set_value("text", "test")
        creator.begin_compound("nested")
        creator.set_value("value", 10)
        creator.set_value("text", "nested")
        creator.set_value("externData", BitBuffer(bytes([0x3C]), 6))
        creator.set_value("bytesData", bytearray([0xFF]))
        creator.set_value("creatorEnum", CreatorEnum.ONE)
        creator.set_value("creatorBitmask", CreatorBitmask.Values.WRITE)
        creator.end_compound()
        creator.begin_array("nestedArray")
        creator.begin_compound_element()
        creator.set_value("value", 5)
        creator.set_value("text", "nestedArray")
        creator.set_value("creatorEnum", CreatorEnum.TWO)
        creator.set_value("creatorBitmask", CreatorBitmask.Values.READ)
        creator.end_compound_element()
        creator.end_array()
        creator.begin_array("textArray")
        creator.add_value_element("this")
        creator.add_value_element("is")
        creator.add_value_element("text")
        creator.add_value_element("array")
        creator.end_array()
        creator.begin_array("externArray")
        creator.add_value_element(BitBuffer(bytes([0x0F]), 4))
        creator.end_array()
        creator.begin_array("bytesArray")
        creator.add_value_element(bytearray([0xCA, 0xFE]))
        creator.end_array()
        creator.set_value("optionalBool", False)
        creator.begin_compound("optionalNested")
        creator.set_value("text", "optionalNested")
        creator.end_compound()
        obj = creator.end_root()

        self.assertEqual(13, obj.value)
        self.assertEqual("test", obj.text)
        self.assertEqual(13, obj.nested.param)
        self.assertEqual(10, obj.nested.value)
        self.assertEqual("nested", obj.nested.text)
        self.assertEqual(bytes([0x3C]), obj.nested.extern_data.buffer)
        self.assertEqual(bytes([0xFF]), obj.nested.bytes_data)
        self.assertEqual(6, obj.nested.extern_data.bitsize)
        self.assertEqual(CreatorEnum.ONE, obj.nested.creator_enum)
        self.assertEqual(CreatorBitmask.Values.WRITE, obj.nested.creator_bitmask)
        self.assertEqual(1, len(obj.nested_array))
        self.assertEqual(5, obj.nested_array[0].value)
        self.assertEqual("nestedArray", obj.nested_array[0].text)
        self.assertEqual(CreatorEnum.TWO, obj.nested_array[0].creator_enum)
        self.assertEqual(CreatorBitmask.Values.READ, obj.nested_array[0].creator_bitmask)
        self.assertEqual(["this", "is", "text", "array"], obj.text_array)
        self.assertEqual(1, len(obj.extern_array))
        self.assertEqual(bytes([0x0F]), obj.extern_array[0].buffer)
        self.assertEqual(4, obj.extern_array[0].bitsize)
        self.assertEqual(1, len(obj.bytes_array))
        self.assertEqual(bytes([0xCA, 0xFE]), obj.bytes_array[0])
        self.assertEqual(False, obj.optional_bool)
        self.assertEqual("optionalNested", obj.optional_nested.text)

    def test_set_value_int_to_float(self):
        # JSON numbers without a fractional part are parsed as int, so an int must be accepted and
        # converted where a float is expected, both for a scalar field and for a float array element.
        class FloatObject:
            def __init__(self):
                self.float_field = None
                self.float_array = None

        float_object_type_info = TypeInfo(
            "FloatObject",
            FloatObject,
            attributes={
                TypeAttribute.FIELDS: [
                    MemberInfo(
                        "floatField",
                        TypeInfo("float32", float),
                        attributes={MemberAttribute.PROPERTY_NAME: "float_field"},
                    ),
                    MemberInfo(
                        "floatArray",
                        TypeInfo("float64", float),
                        attributes={
                            MemberAttribute.PROPERTY_NAME: "float_array",
                            MemberAttribute.ARRAY_LENGTH: None,
                        },
                    ),
                ]
            },
        )

        creator = ZserioTreeCreator(float_object_type_info)
        creator.begin_root()
        creator.set_value("floatField", 13)  # int accepted where float32 is expected
        creator.begin_array("floatArray")
        creator.add_value_element(0)  # int accepted where float64 element is expected
        creator.add_value_element(1)
        creator.end_array()
        obj = creator.end_root()

        self.assertIsInstance(obj.float_field, float)
        self.assertEqual(13.0, obj.float_field)
        self.assertEqual([0.0, 1.0], obj.float_array)
        for element in obj.float_array:
            self.assertIsInstance(element, float)

    def test_exceptions_before_root(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())

        with self.assertRaises(PythonRuntimeException):
            creator.end_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nestedArray")
        with self.assertRaises(PythonRuntimeException):
            creator.end_array()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nested")
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound()
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("value", 13)
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)

    def test_exceptions_in_root(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())

        creator.begin_root()

        with self.assertRaises(PythonRuntimeException):
            creator.begin_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nested")  # not an array
        with self.assertRaises(PythonRuntimeException):
            creator.end_array()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nestedArray")  # is array
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound()
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nonexistent", 13)
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nestedArray", 13)  # is array
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)

    def test_exceptions_in_compound(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())

        creator.begin_root()
        creator.begin_compound("nested")

        with self.assertRaises(PythonRuntimeException):
            creator.begin_root()
        with self.assertRaises(PythonRuntimeException):
            creator.end_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("value")  # not an array
        with self.assertRaises(PythonRuntimeException):
            creator.end_array()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("text")  # not a compound
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nonexistent", "test")
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("value", "test")  # wrong type
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)
        with self.assertRaises(PythonRuntimeException):
            creator.get_element_type()

    def test_exceptions_in_compound_array(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())
        creator.begin_root()
        creator.begin_array("nestedArray")

        with self.assertRaises(PythonRuntimeException):
            creator.begin_root()
        with self.assertRaises(PythonRuntimeException):
            creator.end_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound()
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nonexistent", 13)
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)
        with self.assertRaises(PythonRuntimeException):
            creator.get_field_type("nonexistent")

    def test_exceptions_in_simple_array(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())
        creator.begin_root()
        creator.begin_array("textArray")

        with self.assertRaises(PythonRuntimeException):
            creator.begin_root()
        with self.assertRaises(PythonRuntimeException):
            creator.end_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound()
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nonexistent", 13)
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound_element()  # not a compound array
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)  # wrong type
        with self.assertRaises(PythonRuntimeException):
            creator.get_field_type("nonexistent")

    def test_exceptions_in_compound_element(self):
        creator = ZserioTreeCreator(CreatorObject.type_info())
        creator.begin_root()
        creator.begin_array("nestedArray")
        creator.begin_compound_element()

        with self.assertRaises(PythonRuntimeException):
            creator.begin_root()
        with self.assertRaises(PythonRuntimeException):
            creator.end_root()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_array("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.end_array()
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound("nonexistent")
        with self.assertRaises(PythonRuntimeException):
            creator.end_compound()
        with self.assertRaises(PythonRuntimeException):
            creator.set_value("nonexistent", 13)
        with self.assertRaises(PythonRuntimeException):
            creator.begin_compound_element()
        with self.assertRaises(PythonRuntimeException):
            creator.add_value_element(13)
