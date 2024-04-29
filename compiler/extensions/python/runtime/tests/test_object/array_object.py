# Automatically generated by Zserio Python generator version 1.0.0 using Zserio core 2.12.0.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import typing
import zserio


class ArrayObject:
    def __init__(self, value_: int = int()) -> None:
        self._value_ = value_

    @classmethod
    def from_reader(cls: typing.Type["ArrayObject"], zserio_reader: zserio.BitStreamReader) -> "ArrayObject":
        self = object.__new__(cls)

        self.read(zserio_reader)

        return self

    @classmethod
    def from_reader_packed(
        cls: typing.Type["ArrayObject"],
        zserio_context: ArrayObject.ZserioPackingContext,
        zserio_reader: zserio.BitStreamReader,
    ) -> "ArrayObject":
        self = object.__new__(cls)

        self.read_packed(zserio_context, zserio_reader)

        return self

    @staticmethod
    def type_info() -> zserio.typeinfo.TypeInfo:
        field_list: typing.List[zserio.typeinfo.MemberInfo] = [
            zserio.typeinfo.MemberInfo(
                "value",
                zserio.typeinfo.TypeInfo("bit:31", int),
                attributes={zserio.typeinfo.MemberAttribute.PROPERTY_NAME: "value"},
            )
        ]
        attribute_list = {zserio.typeinfo.TypeAttribute.FIELDS: field_list}

        return zserio.typeinfo.TypeInfo("test_object.ArrayObject", ArrayObject, attributes=attribute_list)

    def __eq__(self, other: object) -> bool:
        if isinstance(other, ArrayObject):
            return self._value_ == other._value_

        return False

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self._value_)

        return result

    @property
    def value(self) -> int:
        return self._value_

    @value.setter
    def value(self, value_: int) -> None:
        self._value_ = value_

    def init_packing_context(self, zserio_context: ArrayObject.ZserioPackingContext) -> None:
        zserio_context.value.init(zserio.array.BitFieldArrayTraits(31), self._value_)

    def bitsizeof(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 31

        return end_bitposition - bitposition

    def bitsizeof_packed(self, zserio_context: ArrayObject.ZserioPackingContext, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += zserio_context.value.bitsizeof(zserio.array.BitFieldArrayTraits(31), self._value_)

        return end_bitposition - bitposition

    def initialize_offsets(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 31

        return end_bitposition

    def initialize_offsets_packed(
        self, zserio_context: ArrayObject.ZserioPackingContext, bitposition: int
    ) -> int:
        end_bitposition = bitposition
        end_bitposition += zserio_context.value.bitsizeof(zserio.array.BitFieldArrayTraits(31), self._value_)

        return end_bitposition

    def read(self, zserio_reader: zserio.BitStreamReader) -> None:
        self._value_ = zserio_reader.read_bits(31)

    def read_packed(
        self,
        zserio_context: ArrayObject.ZserioPackingContext,
        zserio_reader: zserio.BitStreamReader,
    ) -> None:
        self._value_ = zserio_context.value.read(zserio.array.BitFieldArrayTraits(31), zserio_reader)

    def write(self, zserio_writer: zserio.BitStreamWriter) -> None:
        zserio_writer.write_bits(self._value_, 31)

    def write_packed(
        self,
        zserio_context: ArrayObject.ZserioPackingContext,
        zserio_writer: zserio.BitStreamWriter,
    ) -> None:
        zserio_context.value.write(zserio.array.BitFieldArrayTraits(31), zserio_writer, self._value_)

    class ZserioPackingContext:
        def __init__(self):
            self._value_ = zserio.array.DeltaContext()

        @property
        def value(self):
            return self._value_
