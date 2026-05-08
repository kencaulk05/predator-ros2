"""
perception.launch.py

Launches the full perception stack:
  - v4l2_camera_node      (USB camera driver → /image_raw, /camera_info)
  - target_tracker_node   (ArUco detection, dual front/back markers)
  - velocity_estimator_node
  - zone_monitor_node

Use this for early testing of camera + ArUco tracking before
the full system (Nav2, behavior, UR3) is ready.

Usage:
  ros2 launch predator_bringup perception.launch.py
  ros2 launch predator_bringup perception.launch.py camera_device:=/dev/video2
  ros2 launch predator_bringup perception.launch.py log_level:=debug
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    # ── Launch arguments ────────────────────────────────────────────────
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation clock if true'
    )

    log_level_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info',
        description='ROS log level: debug | info | warn | error'
    )

    camera_device_arg = DeclareLaunchArgument(
        'camera_device',
        default_value='/dev/video0',
        description='V4L2 camera device path — override if your camera is not /dev/video0'
    )

    # ── Shared substitutions ────────────────────────────────────────────
    use_sim_time   = LaunchConfiguration('use_sim_time')
    log_level      = LaunchConfiguration('log_level')
    camera_device  = LaunchConfiguration('camera_device')

    config_dir = FindPackageShare('predator_bringup')

    # ── Nodes ───────────────────────────────────────────────────────────

    # USB camera driver — publishes /image_raw and /camera_info
    # Install: sudo apt install ros-kilted-v4l2-camera
    camera = Node(
        package='v4l2_camera',
        executable='v4l2_camera_node',
        name='camera',
        output='screen',
        parameters=[
            PathJoinSubstitution([config_dir, 'config', 'perception.yaml']),
            {
                'video_device': camera_device,
                'use_sim_time': use_sim_time,
            },
        ],
    )

    target_tracker = Node(
        package='predator_perception',
        executable='target_tracker_node',
        name='target_tracker',
        output='screen',
        parameters=[
            PathJoinSubstitution([config_dir, 'config', 'perception.yaml']),
            {'use_sim_time': use_sim_time},
        ],
        arguments=['--ros-args', '--log-level', log_level],
    )

    velocity_estimator = Node(
        package='predator_perception',
        executable='velocity_estimator_node',
        name='velocity_estimator',
        output='screen',
        parameters=[
            PathJoinSubstitution([config_dir, 'config', 'perception.yaml']),
            {'use_sim_time': use_sim_time},
        ],
        arguments=['--ros-args', '--log-level', log_level],
    )

    zone_monitor = Node(
        package='predator_perception',
        executable='zone_monitor_node',
        name='zone_monitor',
        output='screen',
        parameters=[
            PathJoinSubstitution([config_dir, 'config', 'zones.yaml']),
            {'use_sim_time': use_sim_time},
        ],
        arguments=['--ros-args', '--log-level', log_level],
    )

    camera_to_map_transform = Node(
        package='predator_perception',
        executable='camera_to_map_transform_node',
        name='camera_to_map_transform',
        output='screen',
        parameters=[
            PathJoinSubstitution([config_dir, 'config', 'perception.yaml']),
            {'use_sim_time': use_sim_time},
        ],
        arguments=['--ros-args', '--log-level', log_level],
    )

    return LaunchDescription([
        use_sim_time_arg,
        log_level_arg,
        camera_device_arg,
        camera,                    # camera must start before tracker
        target_tracker,
        velocity_estimator,
        zone_monitor,
        camera_to_map_transform,   # must start after target_tracker
    ])
