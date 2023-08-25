# Automatically generated by Zserio Python extension version 2.11.0.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import typing
import zserio

import test_object.walker_nested
import test_object.walker_union

class WalkerObject:
    def __init__(
            self,
            identifier_: int = int(),
            nested_: typing.Optional[test_object.walker_nested.WalkerNested] = None,
            text_: str = str(),
            union_array_: typing.List[test_object.walker_union.WalkerUnion] = None,
            optional_union_array_: typing.Optional[typing.List[test_object.walker_union.WalkerUnion]] = None) -> None:
        self._identifier_ = identifier_
        self._nested_ = nested_
        self._text_ = text_
        self._union_array_ = zserio.array.Array(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_union_array()), union_array_, is_auto=True)
        if optional_union_array_ is None:
            self._optional_union_array_ = None
        else:
            self._optional_union_array_ = zserio.array.Array(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_optional_union_array()), optional_union_array_, is_auto=True)

    @classmethod
    def from_reader(
            cls: typing.Type['WalkerObject'],
            zserio_reader: zserio.BitStreamReader) -> 'WalkerObject':
        self = object.__new__(cls)

        self.read(zserio_reader)

        return self

    @classmethod
    def from_reader_packed(
            cls: typing.Type['WalkerObject'],
            zserio_context: WalkerObject.ZserioPackingContext,
            zserio_reader: zserio.BitStreamReader) -> 'WalkerObject':
        self = object.__new__(cls)

        self.read_packed(zserio_context, zserio_reader)

        return self

    @staticmethod
    def type_info() -> zserio.typeinfo.TypeInfo:
        field_list: typing.List[zserio.typeinfo.MemberInfo] = [
            zserio.typeinfo.MemberInfo(
                'identifier', zserio.typeinfo.TypeInfo('uint32', int),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME : 'identifier'
                }
            ),
            zserio.typeinfo.MemberInfo(
                'nested', test_object.walker_nested.WalkerNested.type_info(),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME : 'nested',
                    zserio.typeinfo.MemberAttribute.OPTIONAL : (lambda self: self._identifier_ != 0),
                    zserio.typeinfo.MemberAttribute.IS_USED_INDICATOR_NAME : 'is_nested_used',
                    zserio.typeinfo.MemberAttribute.IS_SET_INDICATOR_NAME : 'is_nested_set'
                }
            ),
            zserio.typeinfo.MemberInfo(
                'text', zserio.typeinfo.TypeInfo('string', str),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME : 'text'
                }
            ),
            zserio.typeinfo.MemberInfo(
                'unionArray', test_object.walker_union.WalkerUnion.type_info(),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME : 'union_array',
                    zserio.typeinfo.MemberAttribute.ARRAY_LENGTH : None
                }
            ),
            zserio.typeinfo.MemberInfo(
                'optionalUnionArray', test_object.walker_union.WalkerUnion.type_info(),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME : 'optional_union_array',
                    zserio.typeinfo.MemberAttribute.ARRAY_LENGTH : None,
                    zserio.typeinfo.MemberAttribute.OPTIONAL : None,
                    zserio.typeinfo.MemberAttribute.IS_USED_INDICATOR_NAME : 'is_optional_union_array_used',
                    zserio.typeinfo.MemberAttribute.IS_SET_INDICATOR_NAME : 'is_optional_union_array_set'
                }
            )
        ]
        attribute_list = {
            zserio.typeinfo.TypeAttribute.FIELDS : field_list
        }

        return zserio.typeinfo.TypeInfo("test_object.WalkerObject", WalkerObject, attributes=attribute_list)

    def __eq__(self, other: object) -> bool:
        if isinstance(other, WalkerObject):
            return ((self._identifier_ == other._identifier_) and
                    (not other.is_nested_used() if not self.is_nested_used() else (self._nested_ == other._nested_)) and
                    (self._text_ == other._text_) and
                    (self._union_array_ == other._union_array_) and
                    (not other.is_optional_union_array_used() if not self.is_optional_union_array_used() else (self._optional_union_array_ == other._optional_union_array_)))

        return False

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self._identifier_)
        if self.is_nested_used():
            result = zserio.hashcode.calc_hashcode_object(result, self._nested_)
        result = zserio.hashcode.calc_hashcode_string(result, self._text_)
        result = zserio.hashcode.calc_hashcode_object(result, self._union_array_)
        if self.is_optional_union_array_used():
            result = zserio.hashcode.calc_hashcode_object(result, self._optional_union_array_)

        return result

    @property
    def identifier(self) -> int:
        return self._identifier_

    @identifier.setter
    def identifier(self, identifier_: int) -> None:
        self._identifier_ = identifier_

    @property
    def nested(self) -> typing.Optional[test_object.walker_nested.WalkerNested]:
        return self._nested_

    @nested.setter
    def nested(self, nested_: typing.Optional[test_object.walker_nested.WalkerNested]) -> None:
        self._nested_ = nested_

    def is_nested_used(self) -> bool:
        return self._identifier_ != 0

    def is_nested_set(self) -> bool:
        return not self._nested_ is None

    def reset_nested(self) -> None:
        self._nested_ = None

    @property
    def text(self) -> str:
        return self._text_

    @text.setter
    def text(self, text_: str) -> None:
        self._text_ = text_

    @property
    def union_array(self) -> typing.List[test_object.walker_union.WalkerUnion]:
        return self._union_array_.raw_array

    @union_array.setter
    def union_array(self, union_array_: typing.List[test_object.walker_union.WalkerUnion]) -> None:
        self._union_array_ = zserio.array.Array(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_union_array()), union_array_, is_auto=True)

    @property
    def optional_union_array(self) -> typing.Optional[typing.List[test_object.walker_union.WalkerUnion]]:
        return None if self._optional_union_array_ is None else self._optional_union_array_.raw_array

    @optional_union_array.setter
    def optional_union_array(self, optional_union_array_: typing.Optional[typing.List[test_object.walker_union.WalkerUnion]]) -> None:
        if optional_union_array_ is None:
            self._optional_union_array_ = None
        else:
            self._optional_union_array_ = zserio.array.Array(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_optional_union_array()), optional_union_array_, is_auto=True)

    def is_optional_union_array_used(self) -> bool:
        return self.is_optional_union_array_set()

    def is_optional_union_array_set(self) -> bool:
        return not self._optional_union_array_ is None

    def reset_optional_union_array(self) -> None:
        self._optional_union_array_ = None

    def init_packing_context(self, zserio_context: WalkerObject.ZserioPackingContext) -> None:
        zserio_context.identifier.init(zserio.array.BitFieldArrayTraits(32), self._identifier_)

    def bitsizeof(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 32
        if self.is_nested_used():
            end_bitposition += self._nested_.bitsizeof(end_bitposition)
        end_bitposition += zserio.bitsizeof.bitsizeof_string(self._text_)
        end_bitposition += self._union_array_.bitsizeof(end_bitposition)
        end_bitposition += 1
        if self.is_optional_union_array_used():
            end_bitposition += self._optional_union_array_.bitsizeof(end_bitposition)

        return end_bitposition - bitposition

    def bitsizeof_packed(self, zserio_context: WalkerObject.ZserioPackingContext, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += zserio_context.identifier.bitsizeof(zserio.array.BitFieldArrayTraits(32), self._identifier_)
        if self.is_nested_used():
            end_bitposition += self._nested_.bitsizeof(end_bitposition)
        end_bitposition += zserio.bitsizeof.bitsizeof_string(self._text_)
        end_bitposition += self._union_array_.bitsizeof_packed(end_bitposition)
        end_bitposition += 1
        if self.is_optional_union_array_used():
            end_bitposition += self._optional_union_array_.bitsizeof_packed(end_bitposition)

        return end_bitposition - bitposition

    def initialize_offsets(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 32
        if self.is_nested_used():
            end_bitposition = self._nested_.initialize_offsets(end_bitposition)
        end_bitposition += zserio.bitsizeof.bitsizeof_string(self._text_)
        end_bitposition = self._union_array_.initialize_offsets(end_bitposition)
        end_bitposition += 1
        if self.is_optional_union_array_used():
            end_bitposition = self._optional_union_array_.initialize_offsets(end_bitposition)

        return end_bitposition

    def initialize_offsets_packed(self, zserio_context: WalkerObject.ZserioPackingContext, bitposition: int) -> int:
        end_bitposition = bitposition
        end_bitposition += zserio_context.identifier.bitsizeof(zserio.array.BitFieldArrayTraits(32), self._identifier_)
        if self.is_nested_used():
            end_bitposition = self._nested_.initialize_offsets(end_bitposition)
        end_bitposition += zserio.bitsizeof.bitsizeof_string(self._text_)
        end_bitposition = self._union_array_.initialize_offsets_packed(end_bitposition)
        end_bitposition += 1
        if self.is_optional_union_array_used():
            end_bitposition = self._optional_union_array_.initialize_offsets_packed(end_bitposition)

        return end_bitposition

    def read(self, zserio_reader: zserio.BitStreamReader) -> None:
        self._identifier_ = zserio_reader.read_bits(32)
        if self.is_nested_used():
            self._nested_ = test_object.walker_nested.WalkerNested.from_reader(zserio_reader)
        else:
            self._nested_ = None
        self._text_ = zserio_reader.read_string()
        self._union_array_ = zserio.array.Array.from_reader(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_union_array()), zserio_reader, is_auto=True)
        if zserio_reader.read_bool():
            self._optional_union_array_ = zserio.array.Array.from_reader(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_optional_union_array()), zserio_reader, is_auto=True)
        else:
            self._optional_union_array_ = None

    def read_packed(self, zserio_context: WalkerObject.ZserioPackingContext, zserio_reader: zserio.BitStreamReader) -> None:
        self._identifier_ = zserio_context.identifier.read(zserio.array.BitFieldArrayTraits(32), zserio_reader)

        if self.is_nested_used():
            self._nested_ = test_object.walker_nested.WalkerNested.from_reader(zserio_reader)
        else:
            self._nested_ = None

        self._text_ = zserio_reader.read_string()

        self._union_array_ = zserio.array.Array.from_reader_packed(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_union_array()), zserio_reader, is_auto=True)

        if zserio_reader.read_bool():
            self._optional_union_array_ = zserio.array.Array.from_reader_packed(zserio.array.ObjectArrayTraits(self.ZserioElementFactory_optional_union_array()), zserio_reader, is_auto=True)
        else:
            self._optional_union_array_ = None

    def write(self, zserio_writer: zserio.BitStreamWriter) -> None:
        zserio_writer.write_bits(self._identifier_, 32)
        if self.is_nested_used():
            self._nested_.write(zserio_writer)
        zserio_writer.write_string(self._text_)
        self._union_array_.write(zserio_writer)
        if self.is_optional_union_array_used():
            zserio_writer.write_bool(True)
            self._optional_union_array_.write(zserio_writer)
        else:
            zserio_writer.write_bool(False)

    def write_packed(self, zserio_context: WalkerObject.ZserioPackingContext,
                     zserio_writer: zserio.BitStreamWriter) -> None:
        zserio_context.identifier.write(zserio.array.BitFieldArrayTraits(32), zserio_writer, self._identifier_)

        if self.is_nested_used():
            self._nested_.write(zserio_writer)

        zserio_writer.write_string(self._text_)

        self._union_array_.write_packed(zserio_writer)

        if self.is_optional_union_array_used():
            zserio_writer.write_bool(True)
            self._optional_union_array_.write_packed(zserio_writer)
        else:
            zserio_writer.write_bool(False)

    class ZserioPackingContext:
        def __init__(self):
            self._identifier_ = zserio.array.DeltaContext()

        @property
        def identifier(self):
            return self._identifier_

    class ZserioElementFactory_union_array:
        IS_OBJECT_PACKABLE = True

        @staticmethod
        def create(zserio_reader: zserio.BitStreamReader, zserio_index: int) -> test_object.walker_union.WalkerUnion:
            del zserio_index
            return test_object.walker_union.WalkerUnion.from_reader(zserio_reader)

        @staticmethod
        def create_packing_context() -> test_object.walker_union.WalkerUnion.ZserioPackingContext:
            return test_object.walker_union.WalkerUnion.ZserioPackingContext()

        @staticmethod
        def create_packed(zserio_context: test_object.walker_union.WalkerUnion.ZserioPackingContext,
                          zserio_reader: zserio.BitStreamReader, zserio_index: int) -> test_object.walker_union.WalkerUnion:
            del zserio_index
            return test_object.walker_union.WalkerUnion.from_reader_packed(zserio_context, zserio_reader)

    class ZserioElementFactory_optional_union_array:
        IS_OBJECT_PACKABLE = True

        @staticmethod
        def create(zserio_reader: zserio.BitStreamReader, zserio_index: int) -> test_object.walker_union.WalkerUnion:
            del zserio_index
            return test_object.walker_union.WalkerUnion.from_reader(zserio_reader)

        @staticmethod
        def create_packing_context() -> test_object.walker_union.WalkerUnion.ZserioPackingContext:
            return test_object.walker_union.WalkerUnion.ZserioPackingContext()

        @staticmethod
        def create_packed(zserio_context: test_object.walker_union.WalkerUnion.ZserioPackingContext,
                          zserio_reader: zserio.BitStreamReader, zserio_index: int) -> test_object.walker_union.WalkerUnion:
            del zserio_index
            return test_object.walker_union.WalkerUnion.from_reader_packed(zserio_context, zserio_reader)
