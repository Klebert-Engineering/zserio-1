# Automatically generated by Zserio Python extension version 2.11.0.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import typing
import zserio

class CreatorBitmask:
    def __init__(self) -> None:
        self._value = 0

    @classmethod
    def from_value(cls: typing.Type['CreatorBitmask'], value: int) -> 'CreatorBitmask':
        if value < 0 or value > 255:
            raise zserio.PythonRuntimeException(f"Value for bitmask 'CreatorBitmask' out of bounds: {value}!")

        instance = cls()
        instance._value = value
        return instance

    @classmethod
    def from_reader(cls: typing.Type['CreatorBitmask'], reader: zserio.BitStreamReader) -> 'CreatorBitmask':
        instance = cls()
        instance._value = reader.read_bits(8)
        return instance

    @classmethod
    def from_reader_packed(cls: typing.Type['CreatorBitmask'],
                           delta_context: zserio.array.DeltaContext,
                           reader: zserio.BitStreamReader) -> 'CreatorBitmask':
        instance = cls()
        instance._value = delta_context.read(zserio.array.BitFieldArrayTraits(8),
                                             reader)
        return instance

    @staticmethod
    def type_info():
        attribute_list = {
            zserio.typeinfo.TypeAttribute.UNDERLYING_TYPE : zserio.typeinfo.TypeInfo('uint8', int),
            zserio.typeinfo.TypeAttribute.BITMASK_VALUES: [
                zserio.typeinfo.ItemInfo('READ', CreatorBitmask.Values.READ),
                zserio.typeinfo.ItemInfo('WRITE', CreatorBitmask.Values.WRITE)
            ]
        }

        return zserio.typeinfo.TypeInfo('test_object.CreatorBitmask', CreatorBitmask, attributes=attribute_list)

    def __eq__(self, other: object) -> bool:
        if isinstance(other, CreatorBitmask):
            return self._value == other._value

        return False

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self._value)
        return result

    def __str__(self) -> str:
        result = ""

        if (self & CreatorBitmask.Values.READ) == CreatorBitmask.Values.READ:
            result += "READ" if not result else " | READ"
        if (self & CreatorBitmask.Values.WRITE) == CreatorBitmask.Values.WRITE:
            result += "WRITE" if not result else " | WRITE"

        return str(self._value) + "[" + result + "]"

    def __or__(self, other: 'CreatorBitmask') -> 'CreatorBitmask':
        return CreatorBitmask.from_value(self._value | other._value)

    def __and__(self, other: 'CreatorBitmask') -> 'CreatorBitmask':
        return CreatorBitmask.from_value(self._value & other._value)

    def __xor__(self, other: 'CreatorBitmask') -> 'CreatorBitmask':
        return CreatorBitmask.from_value(self._value ^ other._value)

    def __invert__(self) -> 'CreatorBitmask':
        return CreatorBitmask.from_value(~self._value & 255)

    @staticmethod
    def create_packing_context() -> zserio.array.DeltaContext:
        return zserio.array.DeltaContext()

    def init_packing_context(self, delta_context: zserio.array.DeltaContext) -> None:
        delta_context.init(zserio.array.BitFieldArrayTraits(8), self._value)

    def bitsizeof(self, _bitposition: int = 0) -> int:
        return 8

    def bitsizeof_packed(self, delta_context: zserio.array.DeltaContext, _bitposition: int) -> int:
        return delta_context.bitsizeof(zserio.array.BitFieldArrayTraits(8),
                                       self._value)

    def initialize_offsets(self, bitposition: int = 0) -> int:
        return bitposition + self.bitsizeof(bitposition)

    def initialize_offsets_packed(self, delta_context: zserio.array.DeltaContext, bitposition: int) -> int:
        return bitposition + self.bitsizeof_packed(delta_context, bitposition)

    def write(self, writer: zserio.BitStreamWriter) -> None:
        writer.write_bits(self._value, 8)

    def write_packed(self, delta_context: zserio.array.DeltaContext, writer: zserio.BitStreamWriter) -> None:
        delta_context.write(zserio.array.BitFieldArrayTraits(8),
                            writer, self._value)

    @property
    def value(self) -> int:
        return self._value

    class Values:
        READ: 'CreatorBitmask' = None
        WRITE: 'CreatorBitmask' = None

CreatorBitmask.Values.READ = CreatorBitmask.from_value(1)
CreatorBitmask.Values.WRITE = CreatorBitmask.from_value(2)
