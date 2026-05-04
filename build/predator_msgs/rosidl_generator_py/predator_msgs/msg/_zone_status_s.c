// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "predator_msgs/msg/detail/zone_status__struct.h"
#include "predator_msgs/msg/detail/zone_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool predator_msgs__msg__zone_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
    if (class_attr == NULL) {
      return false;
    }
    PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
    if (name_attr == NULL) {
      Py_DECREF(class_attr);
      return false;
    }
    PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
    if (module_attr == NULL) {
      Py_DECREF(name_attr);
      Py_DECREF(class_attr);
      return false;
    }

    // PyUnicode_1BYTE_DATA is just a cast
    assert(strncmp("predator_msgs.msg._zone_status", (char *)PyUnicode_1BYTE_DATA(module_attr), 30) == 0);
    assert(strncmp("ZoneStatus", (char *)PyUnicode_1BYTE_DATA(name_attr), 10) == 0);

    Py_DECREF(module_attr);
    Py_DECREF(name_attr);
    Py_DECREF(class_attr);
  }
  predator_msgs__msg__ZoneStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // target_in_ur3_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_in_ur3_zone");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->target_in_ur3_zone = (Py_True == field);
    Py_DECREF(field);
  }
  {  // target_in_safety_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_in_safety_zone");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->target_in_safety_zone = (Py_True == field);
    Py_DECREF(field);
  }
  {  // distance_to_zone_center
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_to_zone_center");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_to_zone_center = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // zone_radius
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_radius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->zone_radius = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // zone_center
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_center");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__point__convert_from_py(field, &ros_message->zone_center)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * predator_msgs__msg__zone_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ZoneStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("predator_msgs.msg._zone_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ZoneStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  predator_msgs__msg__ZoneStatus * ros_message = (predator_msgs__msg__ZoneStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_in_ur3_zone
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->target_in_ur3_zone ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_in_ur3_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_in_safety_zone
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->target_in_safety_zone ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_in_safety_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_to_zone_center
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_to_zone_center);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_to_zone_center", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_radius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->zone_radius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_radius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_center
    PyObject * field = NULL;
    field = geometry_msgs__msg__point__convert_to_py(&ros_message->zone_center);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_center", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
