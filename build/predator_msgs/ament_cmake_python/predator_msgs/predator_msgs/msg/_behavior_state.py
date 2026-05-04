# generated from rosidl_generator_py/resource/_idl.py.em
# with input from predator_msgs:msg/BehaviorState.idl
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


class Metaclass_BehaviorState(type):
    """Metaclass of message 'BehaviorState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SEARCH': 0,
        'ACQUIRE': 1,
        'PURSUIT': 2,
        'HERD': 3,
        'ARM_ALERT': 4,
        'SAFETY_STOP': 5,
        'REACQUIRE': 6,
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
                'predator_msgs.msg.BehaviorState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__behavior_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__behavior_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__behavior_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__behavior_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__behavior_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SEARCH': cls.__constants['SEARCH'],
            'ACQUIRE': cls.__constants['ACQUIRE'],
            'PURSUIT': cls.__constants['PURSUIT'],
            'HERD': cls.__constants['HERD'],
            'ARM_ALERT': cls.__constants['ARM_ALERT'],
            'SAFETY_STOP': cls.__constants['SAFETY_STOP'],
            'REACQUIRE': cls.__constants['REACQUIRE'],
        }

    @property
    def SEARCH(self):
        """Message constant 'SEARCH'."""
        return Metaclass_BehaviorState.__constants['SEARCH']

    @property
    def ACQUIRE(self):
        """Message constant 'ACQUIRE'."""
        return Metaclass_BehaviorState.__constants['ACQUIRE']

    @property
    def PURSUIT(self):
        """Message constant 'PURSUIT'."""
        return Metaclass_BehaviorState.__constants['PURSUIT']

    @property
    def HERD(self):
        """Message constant 'HERD'."""
        return Metaclass_BehaviorState.__constants['HERD']

    @property
    def ARM_ALERT(self):
        """Message constant 'ARM_ALERT'."""
        return Metaclass_BehaviorState.__constants['ARM_ALERT']

    @property
    def SAFETY_STOP(self):
        """Message constant 'SAFETY_STOP'."""
        return Metaclass_BehaviorState.__constants['SAFETY_STOP']

    @property
    def REACQUIRE(self):
        """Message constant 'REACQUIRE'."""
        return Metaclass_BehaviorState.__constants['REACQUIRE']


class BehaviorState(metaclass=Metaclass_BehaviorState):
    """
    Message class 'BehaviorState'.

    Constants:
      SEARCH
      ACQUIRE
      PURSUIT
      HERD
      ARM_ALERT
      SAFETY_STOP
      REACQUIRE
    """

    __slots__ = [
        '_header',
        '_state',
        '_state_label',
        '_time_in_state',
        '_transition_reason',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'state': 'uint8',
        'state_label': 'string',
        'time_in_state': 'float',
        'transition_reason': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.state = kwargs.get('state', int())
        self.state_label = kwargs.get('state_label', str())
        self.time_in_state = kwargs.get('time_in_state', float())
        self.transition_reason = kwargs.get('transition_reason', str())

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
        if self.state != other.state:
            return False
        if self.state_label != other.state_label:
            return False
        if self.time_in_state != other.time_in_state:
            return False
        if self.transition_reason != other.transition_reason:
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
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def state_label(self):
        """Message field 'state_label'."""
        return self._state_label

    @state_label.setter
    def state_label(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'state_label' field must be of type 'str'"
        self._state_label = value

    @builtins.property
    def time_in_state(self):
        """Message field 'time_in_state'."""
        return self._time_in_state

    @time_in_state.setter
    def time_in_state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'time_in_state' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'time_in_state' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._time_in_state = value

    @builtins.property
    def transition_reason(self):
        """Message field 'transition_reason'."""
        return self._transition_reason

    @transition_reason.setter
    def transition_reason(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'transition_reason' field must be of type 'str'"
        self._transition_reason = value
