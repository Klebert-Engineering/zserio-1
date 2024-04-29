# Automatically generated by Zserio Python generator version 1.0.0 using Zserio core 2.12.0.
# Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode

from __future__ import annotations

import typing
import zserio

import test_object.serialize_nested


class SerializeObject:
    def __init__(
        self,
        param_: int = int(),
        nested_: typing.Union[test_object.serialize_nested.SerializeNested, None] = None,
    ) -> None:
        self._param_ = param_
        self._nested_ = nested_

    @classmethod
    def from_reader(
        cls: typing.Type["SerializeObject"], zserio_reader: zserio.BitStreamReader
    ) -> "SerializeObject":
        self = object.__new__(cls)

        self.read(zserio_reader)

        return self

    @staticmethod
    def type_info() -> zserio.typeinfo.TypeInfo:
        field_list: typing.List[zserio.typeinfo.MemberInfo] = [
            zserio.typeinfo.MemberInfo(
                "param",
                zserio.typeinfo.TypeInfo("int8", int),
                attributes={zserio.typeinfo.MemberAttribute.PROPERTY_NAME: "param"},
            ),
            zserio.typeinfo.MemberInfo(
                "nested",
                test_object.serialize_nested.SerializeNested.type_info(),
                attributes={
                    zserio.typeinfo.MemberAttribute.PROPERTY_NAME: "nested",
                    zserio.typeinfo.MemberAttribute.TYPE_ARGUMENTS: [(lambda self, zserio_index: self._param_)],
                },
            ),
        ]
        attribute_list = {zserio.typeinfo.TypeAttribute.FIELDS: field_list}

        return zserio.typeinfo.TypeInfo(
            "test_object.SerializeObject", SerializeObject, attributes=attribute_list
        )

    def __eq__(self, other: object) -> bool:
        if isinstance(other, SerializeObject):
            return (self._param_ == other._param_) and (self._nested_ == other._nested_)

        return False

    def __hash__(self) -> int:
        result = zserio.hashcode.HASH_SEED
        result = zserio.hashcode.calc_hashcode_int32(result, self._param_)
        result = zserio.hashcode.calc_hashcode_object(result, self._nested_)

        return result

    @property
    def param(self) -> int:
        return self._param_

    @param.setter
    def param(self, param_: int) -> None:
        self._param_ = param_

    @property
    def nested(
        self,
    ) -> typing.Union[test_object.serialize_nested.SerializeNested, None]:
        return self._nested_

    @nested.setter
    def nested(self, nested_: typing.Union[test_object.serialize_nested.SerializeNested, None]) -> None:
        self._nested_ = nested_

    def bitsizeof(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 8
        end_bitposition += self._nested_.bitsizeof(end_bitposition)

        return end_bitposition - bitposition

    def initialize_offsets(self, bitposition: int = 0) -> int:
        end_bitposition = bitposition
        end_bitposition += 8
        end_bitposition = self._nested_.initialize_offsets(end_bitposition)

        return end_bitposition

    def read(self, zserio_reader: zserio.BitStreamReader) -> None:
        self._param_ = zserio_reader.read_signed_bits(8)
        self._nested_ = test_object.serialize_nested.SerializeNested.from_reader(zserio_reader, self._param_)

    def write(self, zserio_writer: zserio.BitStreamWriter) -> None:
        zserio_writer.write_signed_bits(self._param_, 8)

        # check parameters
        if self._nested_.param != (self._param_):
            raise zserio.PythonRuntimeException(
                "Wrong parameter param for field SerializeObject.nested: "
                f"{self._nested_.param} != {self._param_}!"
            )
        self._nested_.write(zserio_writer)
