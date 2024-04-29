# Automatically generated by Zserio Python generator version 1.0.0 using Zserio core 2.12.0.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import typing
import zserio


class SerializeEnum(zserio.Enum):
    VALUE1 = 0
    VALUE2 = 1
    VALUE3 = 2

    @classmethod
    def from_name(cls: typing.Type["SerializeEnum"], item_name: str) -> "SerializeEnum":
        if item_name == "VALUE1":
            item = SerializeEnum.VALUE1
        elif item_name == "VALUE2":
            item = SerializeEnum.VALUE2
        elif item_name == "VALUE3":
            item = SerializeEnum.VALUE3
        else:
            raise zserio.PythonRuntimeException(
                f"Enum item '{item_name}' doesn't exist in enum 'SerializeEnum'!"
            )

        return item

    @classmethod
    def from_reader(cls: typing.Type["SerializeEnum"], reader: zserio.BitStreamReader) -> "SerializeEnum":
        return cls(reader.read_bits(8))

    @staticmethod
    def type_info():
        attribute_list = {
            zserio.typeinfo.TypeAttribute.UNDERLYING_TYPE: zserio.typeinfo.TypeInfo("uint8", int),
            zserio.typeinfo.TypeAttribute.ENUM_ITEMS: [
                zserio.typeinfo.ItemInfo("VALUE1", SerializeEnum.VALUE1, False, False),
                zserio.typeinfo.ItemInfo("VALUE2", SerializeEnum.VALUE2, False, False),
                zserio.typeinfo.ItemInfo("VALUE3", SerializeEnum.VALUE3, False, False),
            ],
        }

        return zserio.typeinfo.TypeInfo("test_object.SerializeEnum", SerializeEnum, attributes=attribute_list)

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self.value)
        return result

    def bitsizeof(self, _bitposition: int = 0) -> int:
        return 8

    def initialize_offsets(self, bitposition: int = 0) -> int:
        return bitposition + self.bitsizeof(bitposition)

    def write(self, writer: zserio.BitStreamWriter) -> None:
        writer.write_bits(self.value, 8)
