"""
The module implements generic walker through given zserio object tree.
"""
import functools
import re
import typing

from zserio.exception import PythonRuntimeException
from zserio.typeinfo import TypeAttribute, MemberInfo, MemberAttribute

class WalkObserver:
    """
    Interface for observers which are called by the walker.
    """

    def begin_root(self, compound: typing.Any) -> None:
        """
        Called for the root compound zserio object which is to be walked-through.

        :param compound: Root compound zserio object.
        """
        raise NotImplementedError()

    def end_root(self, compound: typing.Any) -> None:
        """
        Called at the end of just walked root compound zserio object.

        :param compound: Root compound zserio object.
        """
        raise NotImplementedError()

    def begin_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> None:
        """
        Called at the beginning of an array.

        :param array: Zserio array.
        :param member_info: Array member info.
        """

        raise NotImplementedError()

    def end_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> None:
        """
        Called at the end of an array.

        :param array: Zserio array.
        :param member_info: Array member info.
        """

        raise NotImplementedError()

    def begin_compound(self, compound: typing.Any, member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> None:
        """
        Called at the beginning of an compound field object.

        Note that for uninitialized compounds (i.e. None) the visit_value method is called instead!

        :param compound: Compound zserio object.
        :param member_info: Compound member info.
        :param element_index: Element index in array or None if the compound is not in array.
        """
        raise NotImplementedError()

    def end_compound(self, compound: typing.Any, member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> None:
        """
        Called at the end of just walked compound object.

        :param compound: Compound zserio object.
        :param member_info: Compound member info.
        :param element_index: Element index in array or None if the compound is not in array.
        """
        raise NotImplementedError()

    def visit_value(self, value: typing.Any, member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> None:
        """
        Called when a simple (or an unset compound - i.e. None) value is reached.

        :param value: Simple value.
        :param member_info: Member info.
        :param element_index: Element index in array or None if the value is not in array.
        """
        raise NotImplementedError()

class WalkFilter:
    """
    Interface for filters which can influence the walking.
    """

    def before_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> bool:
        """
        Called before an array.

        :param array: Zserio array.
        :param member_info: Array member info.

        :return: True when the walking should continue to the array.
        """
        raise NotImplementedError()

    def after_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> bool:
        """
        Called after an array.

        :param array: Zserio array.
        :param member_info: Array member info.

        :returns: True when the walking should continue to a next sibling, False to return to the parent.
        """

        raise NotImplementedError()

    def before_compound(self, compound: typing.Any, member_info: MemberInfo,
                        element_index: typing.Optional[int] = None) -> bool:
        """
        Called before a compound object.

        Note that for uninitialized compounds (i.e. None) the before_value method is called instead!

        :param compound: Compound zserio object.
        :param member_info: Compound member info.
        :param element_index: Element index in array or None if the compound is not in array.

        :returns: True when the walking should continue into the compound object, False otherwise.
        """
        raise NotImplementedError()

    def after_compound(self, compound: typing.Any, member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> bool:
        """
        Called after a compound object.

        :param compound: Compound zserio object.
        :param member_info: Compound member info.
        :param element_index: Element index in array or None if the compound is not in array.

        :returns: True when the walking should continue to a next sibling, False to return to the parent.
        """
        raise NotImplementedError()

    def before_value(self, value: typing.Any, member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> bool:
        """
        Called before a simple (or an unset compound - i.e. None) value.

        :param value: Simple value.
        :param member_info: Member info.
        :param element_index: Element index in array or None if the value is not in array.

        :returns: True when the walking should continue to the simple value, False otherwise.
        """
        raise NotImplementedError()

    def after_value(self, value: typing.Any, member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> bool:
        """
        Called after a simple value.

        :param value: Simple value.
        :param member_info: Member info.
        :param element_index: Element index in array or None if the value is not in array.

        :returns: True when the walking should continue to a next sibling, False to return to the parent.
        """
        raise NotImplementedError()

class Walker:
    """
    Walker through zserio objects, based on generated type info (see -withTypeInfoCode).
    """

    def __init__(self, walk_observer: WalkObserver, walk_filter: typing.Optional[WalkFilter] = None) -> None:
        """
        Constructor.

        :param walk_observer: Observer to use during walking.
        :param walk_filter: Walk filter to use.
        """

        self._walk_observer = walk_observer
        self._walk_filter = walk_filter if walk_filter is not None else DefaultWalkFilter()

    def walk(self, zserio_object: typing.Any) -> None:
        """
        Walks given zserio object which must be generated with type_info (see -withTypeInfoCode options).

        :param zserio_object: Zserio object to walk.
        """

        if not hasattr(zserio_object, "type_info"):
            raise PythonRuntimeException("Type info must be enabled (see zserio option -withTypeInfoCode)!")

        self._walk_observer.begin_root(zserio_object)
        self._walk_fields(zserio_object, zserio_object.type_info())
        self._walk_observer.end_root(zserio_object)

    def _walk_field(self, zserio_object: typing.Any, member_info: MemberInfo) -> bool:
        if MemberAttribute.ARRAY_LENGTH in member_info.attributes and zserio_object is not None:
            if self._walk_filter.before_array(zserio_object, member_info):
                self._walk_observer.begin_array(zserio_object, member_info)
                for index, element in enumerate(zserio_object):
                    if not self._walk_field_value(element, member_info, index):
                        break
                self._walk_observer.end_array(zserio_object, member_info)
            return self._walk_filter.after_array(zserio_object, member_info)
        else:
            return self._walk_field_value(zserio_object, member_info)

    def _walk_field_value(self, zserio_object: typing.Any, member_info: MemberInfo,
                          element_index: typing.Optional[int] = None) -> bool:
        type_info = member_info.type_info
        if TypeAttribute.FIELDS not in type_info.attributes or zserio_object is None: # simple field
            if self._walk_filter.before_value(zserio_object, member_info, element_index):
                self._walk_observer.visit_value(zserio_object, member_info, element_index)
            return self._walk_filter.after_value(zserio_object, member_info, element_index)
        else:
            if self._walk_filter.before_compound(zserio_object, member_info, element_index):
                self._walk_observer.begin_compound(zserio_object, member_info, element_index)
                self._walk_fields(zserio_object, type_info)
                self._walk_observer.end_compound(zserio_object, member_info, element_index)
            return self._walk_filter.after_compound(zserio_object, member_info, element_index)

    def _walk_fields(self, zserio_object, type_info) -> None:
        if TypeAttribute.FIELDS in type_info.attributes:
            fields = type_info.attributes[TypeAttribute.FIELDS]
            if TypeAttribute.SELECTOR in type_info.attributes:
                # union or choice
                choice_tag = zserio_object.choice_tag
                if choice_tag != zserio_object.UNDEFINED_CHOICE:
                    field = fields[choice_tag]
                    self._walk_field(getattr(zserio_object, field.attributes[MemberAttribute.PROPERTY_NAME]),
                                     field)
                # else: uninitialized or empty branch
            else:
                # structure
                for field in fields:
                    if not self._walk_field(getattr(zserio_object,
                                                    field.attributes[MemberAttribute.PROPERTY_NAME]),
                                            field):
                        break

class DefaultWalkObserver(WalkObserver):
    """
    Default walk observer which just does nothing.
    """

    def begin_root(self, _root: typing.Any) -> None:
        pass

    def end_root(self, _root: typing.Any) -> None:
        pass

    def begin_array(self, _array: typing.List[typing.Any], member_info: MemberInfo) -> None:
        pass

    def end_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> None:
        pass

    def begin_compound(self, _compound: typing.Any, member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> None:
        pass

    def end_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> None:
        pass

    def visit_value(self, _value : typing.Any, member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> None:
        pass

class DefaultWalkFilter(WalkFilter):
    """
    Default walk filter which filters nothing.
    """

    def before_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        return True

    def after_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        return True

    def before_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                        _element_index: typing.Optional[int] = None) -> bool:
        return True

    def after_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                       _element_index: typing.Optional[int] = None) -> bool:
        return True

    def before_value(self, _value: typing.Any, _member_info: MemberInfo,
                     _element_index: typing.Optional[int] = None) -> bool:
        return True

    def after_value(self, _value: typing.Any, _member_info: MemberInfo,
                    _element_index: typing.Optional[int] = None) -> bool:
        return True

class DepthWalkFilter(WalkFilter):
    """
    Walk filter which allows to walk only to the given maximum depth.
    """

    def __init__(self, max_depth: int):
        """
        Constructor.

        :param max_depth: Maximum depth to walk to.
        """

        self._max_depth = max_depth
        self._depth = 1

    def before_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        enter = self._depth <= self._max_depth
        self._depth += 1
        return enter

    def after_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        self._depth -= 1
        return True

    def before_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                        _element_index: typing.Optional[int] = None) -> bool:
        enter = self._depth <= self._max_depth
        self._depth += 1
        return enter

    def after_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                       _element_index: typing.Optional[int] = None) -> bool:
        self._depth -= 1
        return True

    def before_value(self, _value: typing.Any, _member_info: MemberInfo,
                     _element_index: typing.Optional[int] = None) -> bool:
        return self._depth <= self._max_depth

    def after_value(self, _value: typing.Any, _member_info: MemberInfo,
                    _element_index: typing.Optional[int] = None) -> bool:
        return True

class RegexWalkFilter(WalkFilter):
    """
    Walk filter which allows to walk only paths matching given regex.

    The path is constructed from field names within the root object, thus the root object
    itself is not part of the path.

    Currently arrays are processed based on field names and it's not possible to specify an index.
    """

    def __init__(self, path_regex: str) -> None:
        """
        Constructor.

        :param path_regex: Path regex to use for filtering.
        """

        self._current_path: typing.List[str] = []
        self._path_regex = re.compile(path_regex)

    def before_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> bool:
        self._current_path.append(member_info.schema_name)
        if self._path_regex.match(self._get_current_path()):
            return True # the array itself matches

        # try to find match in each element and continue into the array only if some match is found
        # (note that array is never None)
        for i, element in enumerate(array):
            self._current_path[-1] = member_info.schema_name + f"[{i}]"
            if self._match_subtree(element, member_info):
                return True
        self._current_path[-1] = member_info.schema_name
        return False

    def after_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        self._current_path.pop()
        return True

    def before_compound(self, compound: typing.Any, member_info: MemberInfo,
                        element_index: typing.Optional[int] = None) -> bool:
        self._append_path(member_info, element_index)
        if self._path_regex.match(self._get_current_path()):
            return True # the compound itself matches

        return self._match_subtree(compound, member_info)

    def after_compound(self, _compound: typing.Any, member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> bool:
        self._pop_path(member_info, element_index)
        return True

    def before_value(self, value: typing.Any, member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> bool:
        self._append_path(member_info, element_index)
        return self._match_subtree(value, member_info)

    def after_value(self, _value: typing.Any, member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> bool:
        self._pop_path(member_info, element_index)
        return True

    def _match_subtree(self, member: typing.Any, member_info: MemberInfo) -> bool:
        if member is not None and TypeAttribute.FIELDS in member_info.type_info.attributes:
            # is a not None compound, try to find match within its subtree
            subtree_regex_filter = self._SubtreeRegexFilter(self._current_path.copy(), self._path_regex)
            walker = Walker(DefaultWalkObserver(), subtree_regex_filter)
            walker.walk(member)
            return subtree_regex_filter.matches()
        else:
            # try to match a simple value or None compound
            return self._path_regex.match(self._get_current_path()) is not None

    def _get_current_path(self):
        return self._get_current_path_impl(self._current_path)

    def _append_path(self, member_info: MemberInfo, element_index: typing.Union[int, None]) -> None:
        self._append_path_impl(self._current_path, member_info, element_index)

    def _pop_path(self, member_info: MemberInfo, element_index: typing.Union[int, None]) -> None:
        self._pop_path_impl(self._current_path, member_info, element_index)

    @staticmethod
    def _get_current_path_impl(current_path: typing.List[str]) -> str:
        return ".".join(current_path)

    @staticmethod
    def _append_path_impl(current_path: typing.List[str], member_info: MemberInfo,
            element_index: typing.Union[int, None]) -> None:
        if element_index is None:
            current_path.append(member_info.schema_name)
        else:
            current_path[-1] = member_info.schema_name + f"[{element_index}]" # add index

    @staticmethod
    def _pop_path_impl(current_path: typing.List[str], member_info: MemberInfo,
            element_index: typing.Union[int, None]) -> None:
        if element_index is None:
            current_path.pop()
        else:
            current_path[-1] = member_info.schema_name # just remove the index

    class _SubtreeRegexFilter(WalkFilter):
        """
        Walks whole subtree and in case of match stops walking. Used to check whether any path
        within the subtree matches given regex.
        """

        def __init__(self, current_path: typing.List[str], path_regex: typing.Pattern) -> None:
            self._current_path = current_path
            self._path_regex = path_regex
            self._matches = False

        def matches(self) -> bool:
            """
            Returns whether the subtree contains any matching value.

            :returns: True when the subtree contains a matching value, False otherwise.
            """

            return self._matches

        def before_array(self, _array: typing.List[typing.Any], member_info: MemberInfo):
            self._current_path.append(member_info.schema_name)
            self._matches = self._path_regex.match(self._get_current_path()) is not None

            # terminate when the match is already found (note that array is never None here)
            return not self._matches

        def after_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo):
            self._current_path.pop()
            return not self._matches # terminate when the match is already found

        def before_compound(self, _compound: typing.Any, member_info: MemberInfo,
                            element_index: typing.Optional[int] = None):
            self._append_path(member_info, element_index)
            self._matches = self._path_regex.match(self._get_current_path()) is not None

            #  terminate when the match is already found (note that compound is never None here)
            return not self._matches

        def after_compound(self, _compound: typing.Any, member_info: MemberInfo,
                           element_index: typing.Optional[int] = None):
            self._pop_path(member_info, element_index)
            return not self._matches # terminate when the match is already found

        def before_value(self, _value: typing.Any, member_info: MemberInfo,
                         element_index: typing.Optional[int] = None):
            self._append_path(member_info, element_index)
            self._matches = self._path_regex.match(self._get_current_path()) is not None

            return not self._matches # terminate when the match is already found

        def after_value(self, _value: typing.Any, member_info: MemberInfo,
                        element_index: typing.Optional[int] = None):
            self._pop_path(member_info, element_index)
            return not self._matches # terminate when the match is already found

        def _get_current_path(self):
            return RegexWalkFilter._get_current_path_impl(self._current_path)

        def _append_path(self, member_info: MemberInfo, element_index: typing.Union[int, None]) -> None:
            return RegexWalkFilter._append_path_impl(self._current_path, member_info, element_index)

        def _pop_path(self, member_info: MemberInfo, element_index: typing.Union[int, None]) -> None:
            return RegexWalkFilter._pop_path_impl(self._current_path, member_info, element_index)

class ArrayLengthWalkFilter(WalkFilter):
    """
    Walk filter which allows to walk only to the given maximum array length.
    """

    def __init__(self, max_array_length: int):
        """
        Constructor.

        :param max_array_length: Maximum array length to walk to.
        """

        self._max_array_length = max_array_length

    def before_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        return True

    def after_array(self, _array: typing.List[typing.Any], _member_info: MemberInfo) -> bool:
        return True

    def before_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                        element_index: typing.Optional[int] = None) -> bool:
        return self._filter_array_element(element_index)

    def after_compound(self, _compound: typing.Any, _member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> bool:
        return self._filter_array_element(element_index)

    def before_value(self, _value: typing.Any, _member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> bool:
        return self._filter_array_element(element_index)

    def after_value(self, _value: typing.Any, _member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> bool:
        return self._filter_array_element(element_index)

    def _filter_array_element(self, element_index: typing.Optional[int]) -> bool:
        return True if element_index is None else element_index < self._max_array_length

class AndWalkFilter(WalkFilter):
    """
    Walk filter which implements composition of particular filters.

    The filters are called sequentially and logical and is applied on theirs results.
    """

    def __init__(self, walk_filters: typing.List[WalkFilter]) -> None:
        """
        Constructor.

        :param walk_filters: List of filters to apply by this walk filter.
        """

        self._walk_filters = walk_filters

    def before_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> bool:
        return self._apply_filters(lambda x: x.before_array(array, member_info))

    def after_array(self, array: typing.List[typing.Any], member_info: MemberInfo) -> bool:
        return self._apply_filters(lambda x: x.after_array(array, member_info))

    def before_compound(self, compound: typing.Any, member_info: MemberInfo,
                        element_index: typing.Optional[int] = None) -> bool:
        return self._apply_filters(lambda x: x.before_compound(compound, member_info, element_index))

    def after_compound(self, compound: typing.Any, member_info: MemberInfo,
                       element_index: typing.Optional[int] = None) -> bool:
        return self._apply_filters(lambda x: x.after_compound(compound, member_info, element_index))

    def before_value(self, value: typing.Any, member_info: MemberInfo,
                     element_index: typing.Optional[int] = None) -> bool:
        return self._apply_filters(lambda x: x.before_value(value, member_info, element_index))

    def after_value(self, value: typing.Any, member_info: MemberInfo,
                    element_index: typing.Optional[int] = None) -> bool:
        return self._apply_filters(lambda x: x.after_value(value, member_info, element_index))

    def _apply_filters(self, method):
        return functools.reduce(lambda x, y: x and y, map(method, self._walk_filters), True)
