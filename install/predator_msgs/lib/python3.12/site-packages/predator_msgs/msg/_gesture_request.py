# generated from rosidl_generator_py/resource/_idl.py.em
# with input from predator_msgs:msg/GestureRequest.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GestureRequest(type):
    """Metaclass of message 'GestureRequest'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GESTURE_NONE': 0,
        'GESTURE_READY': 1,
        'GESTURE_POINT': 2,
        'GESTURE_FREEZE': 3,
        'GESTURE_RESET': 4,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('predator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'predator_msgs.msg.GestureRequest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gesture_request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gesture_request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gesture_request
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gesture_request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gesture_request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GESTURE_NONE': cls.__constants['GESTURE_NONE'],
            'GESTURE_READY': cls.__constants['GESTURE_READY'],
            'GESTURE_POINT': cls.__constants['GESTURE_POINT'],
            'GESTURE_FREEZE': cls.__constants['GESTURE_FREEZE'],
            'GESTURE_RESET': cls.__constants['GESTURE_RESET'],
        }

    @property
    def GESTURE_NONE(self):
        """Message constant 'GESTURE_NONE'."""
        return Metaclass_GestureRequest.__constants['GESTURE_NONE']

    @property
    def GESTURE_READY(self):
        """Message constant 'GESTURE_READY'."""
        return Metaclass_GestureRequest.__constants['GESTURE_READY']

    @property
    def GESTURE_POINT(self):
        """Message constant 'GESTURE_POINT'."""
        return Metaclass_GestureRequest.__constants['GESTURE_POINT']

    @property
    def GESTURE_FREEZE(self):
        """Message constant 'GESTURE_FREEZE'."""
        return Metaclass_GestureRequest.__constants['GESTURE_FREEZE']

    @property
    def GESTURE_RESET(self):
        """Message constant 'GESTURE_RESET'."""
        return Metaclass_GestureRequest.__constants['GESTURE_RESET']


class GestureRequest(metaclass=Metaclass_GestureRequest):
    """
    Message class 'GestureRequest'.

    Constants:
      GESTURE_NONE
      GESTURE_READY
      GESTURE_POINT
      GESTURE_FREEZE
      GESTURE_RESET
    """

    __slots__ = [
        '_header',
        '_gesture_type',
        '_target_point',
        '_urgency',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'gesture_type': 'uint8',
        'target_point': 'geometry_msgs/Point',
        'urgency': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.gesture_type = kwargs.get('gesture_type', int())
        from geometry_msgs.msg import Point
        self.target_point = kwargs.get('target_point', Point())
        self.urgency = kwargs.get('urgency', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.gesture_type != other.gesture_type:
            return False
        if self.target_point != other.target_point:
            return False
        if self.urgency != other.urgency:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def gesture_type(self):
        """Message field 'gesture_type'."""
        return self._gesture_type

    @gesture_type.setter
    def gesture_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gesture_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gesture_type' field must be an unsigned integer in [0, 255]"
        self._gesture_type = value

    @builtins.property
    def target_point(self):
        """Message field 'target_point'."""
        return self._target_point

    @target_point.setter
    def target_point(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'target_point' field must be a sub message of type 'Point'"
        self._target_point = value

    @builtins.property
    def urgency(self):
        """Message field 'urgency'."""
        return self._urgency

    @urgency.setter
    def urgency(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'urgency' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'urgency' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._urgency = value
