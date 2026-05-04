# generated from rosidl_generator_py/resource/_idl.py.em
# with input from predator_msgs:msg/ZoneStatus.idl
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


class Metaclass_ZoneStatus(type):
    """Metaclass of message 'ZoneStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'predator_msgs.msg.ZoneStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__zone_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__zone_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__zone_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__zone_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__zone_status

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
        }


class ZoneStatus(metaclass=Metaclass_ZoneStatus):
    """Message class 'ZoneStatus'."""

    __slots__ = [
        '_header',
        '_target_in_ur3_zone',
        '_target_in_safety_zone',
        '_distance_to_zone_center',
        '_zone_radius',
        '_zone_center',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'target_in_ur3_zone': 'boolean',
        'target_in_safety_zone': 'boolean',
        'distance_to_zone_center': 'float',
        'zone_radius': 'float',
        'zone_center': 'geometry_msgs/Point',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
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
        self.target_in_ur3_zone = kwargs.get('target_in_ur3_zone', bool())
        self.target_in_safety_zone = kwargs.get('target_in_safety_zone', bool())
        self.distance_to_zone_center = kwargs.get('distance_to_zone_center', float())
        self.zone_radius = kwargs.get('zone_radius', float())
        from geometry_msgs.msg import Point
        self.zone_center = kwargs.get('zone_center', Point())

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
        if self.target_in_ur3_zone != other.target_in_ur3_zone:
            return False
        if self.target_in_safety_zone != other.target_in_safety_zone:
            return False
        if self.distance_to_zone_center != other.distance_to_zone_center:
            return False
        if self.zone_radius != other.zone_radius:
            return False
        if self.zone_center != other.zone_center:
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
    def target_in_ur3_zone(self):
        """Message field 'target_in_ur3_zone'."""
        return self._target_in_ur3_zone

    @target_in_ur3_zone.setter
    def target_in_ur3_zone(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'target_in_ur3_zone' field must be of type 'bool'"
        self._target_in_ur3_zone = value

    @builtins.property
    def target_in_safety_zone(self):
        """Message field 'target_in_safety_zone'."""
        return self._target_in_safety_zone

    @target_in_safety_zone.setter
    def target_in_safety_zone(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'target_in_safety_zone' field must be of type 'bool'"
        self._target_in_safety_zone = value

    @builtins.property
    def distance_to_zone_center(self):
        """Message field 'distance_to_zone_center'."""
        return self._distance_to_zone_center

    @distance_to_zone_center.setter
    def distance_to_zone_center(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'distance_to_zone_center' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance_to_zone_center' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance_to_zone_center = value

    @builtins.property
    def zone_radius(self):
        """Message field 'zone_radius'."""
        return self._zone_radius

    @zone_radius.setter
    def zone_radius(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'zone_radius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'zone_radius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._zone_radius = value

    @builtins.property
    def zone_center(self):
        """Message field 'zone_center'."""
        return self._zone_center

    @zone_center.setter
    def zone_center(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'zone_center' field must be a sub message of type 'Point'"
        self._zone_center = value
