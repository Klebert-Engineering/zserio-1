# Automatically generated by Zserio Python extension version 2.9.0-pre1.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import enum
import typing
import zserio

class SerializeEnum(enum.Enum):
    VALUE1 = 0
    VALUE2 = 1
    VALUE3 = 2

    @classmethod
    def from_reader(cls: typing.Type['SerializeEnum'], reader: zserio.BitStreamReader) -> 'SerializeEnum':
        return cls(reader.read_bits(8))

    @classmethod
    def from_reader_packed(cls: typing.Type['SerializeEnum'],
                           context_node: zserio.array.PackingContextNode,
                           reader: zserio.BitStreamReader) -> 'SerializeEnum':
        return cls(context_node.context.read(zserio.array.BitFieldArrayTraits(8), reader))

    @staticmethod
    def type_info():
        attribute_list = {
            zserio.typeinfo.TypeAttribute.UNDERLYING_TYPE : zserio.typeinfo.TypeInfo('uint8', int),
            zserio.typeinfo.TypeAttribute.ENUM_ITEMS: [
                zserio.typeinfo.ItemInfo('VALUE1', SerializeEnum.VALUE1),
                zserio.typeinfo.ItemInfo('VALUE2', SerializeEnum.VALUE2),
                zserio.typeinfo.ItemInfo('VALUE3', SerializeEnum.VALUE3)
            ]
        }

        return zserio.typeinfo.TypeInfo('test_object.SerializeEnum', SerializeEnum, attributes=attribute_list)

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self.value)
        return result

    @staticmethod
    def create_packing_context(context_node: zserio.array.PackingContextNode) -> None:
        context_node.create_context()

    def init_packing_context(self, context_node: zserio.array.PackingContextNode) -> None:
        context_node.context.init(zserio.array.BitFieldArrayTraits(8),
                                  self.value)

    def bitsizeof(self, _bitposition: int = 0) -> int:
        return 8

    def bitsizeof_packed(self, context_node: zserio.array.PackingContextNode,
                         _bitposition: int) -> int:
        return context_node.context.bitsizeof(zserio.array.BitFieldArrayTraits(8),
                                              self.value)

    def initialize_offsets(self, bitposition: int = 0) -> int:
        return bitposition + self.bitsizeof(bitposition)

    def initialize_offsets_packed(self, context_node: zserio.array.PackingContextNode,
                                  bitposition: int) -> int:
        return bitposition + self.bitsizeof_packed(context_node, bitposition)

    def write(self, writer: zserio.BitStreamWriter) -> None:
        writer.write_bits(self.value, 8)

    def write_packed(self, context_node: zserio.array.PackingContextNode,
                     writer: zserio.BitStreamWriter) -> None:
        context_node.context.write(zserio.array.BitFieldArrayTraits(8), writer, self.value)
