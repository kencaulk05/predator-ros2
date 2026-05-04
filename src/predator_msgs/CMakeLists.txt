cmake_minimum_required(VERSION 3.20)
project(predator_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
"msg/BehaviorState.msg"
"msg/GestureRequest.msg"
"msg/TargetState.msg"
"msg/ZoneStatus.msg"
DEPENDENCIES geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_export_dependencies(geometry_msgs)

if(BUILD_TESTING)
find_package(ament_lint_auto REQUIRED)
set(ament_cmake_copyright_FOUND TRUE)
set(ament_cmake_cpplint_FOUND TRUE)
ament_lint_auto_find_test_dependencies()
endif()

ament_package()
