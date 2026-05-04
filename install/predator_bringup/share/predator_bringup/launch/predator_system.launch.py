"""
predator_system.launch.py

Full system launch for the predator biomimetic robot:
  - Perception  : target_tracker, velocity_estimator, zone_monitor
  - Behavior    : behavior_manager, safety_supervisor
  - Navigation  : pursuit_planner  (+ Nav2 — see TODO below)
  - Manipulation: arm_gesture      (+ UR3/MoveIt — commented out until hardware confirmed)

Usage:
  ros2 launch predator_bringup predator_system.launch.py
  ros2 launch predator_bringup predator_system.launch.py log_level:=debug
  ros2 launch predator_bringup predator_system.launch.py use_sim_time:=true
"""

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    GroupAction,
    IncludeLaunchDescription,
    LogInfo,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
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

    # ── Shared substitutions ────────────────────────────────────────────
    use_sim_time = LaunchConfiguration('use_sim_time')
    log_level    = LaunchConfiguration('log_level')

    bringup_share = FindPackageShare('predator_bringup')

    # ── Helper: build path to a config file ────────────────────────────
    def cfg(filename):
        return PathJoinSubstitution([bringup_share, 'config', filename])

    # ─────────────────────────────────────────────────────────────────────
    # 1. PERCEPTION
    # ─────────────────────────────────────────────────────────────────────
    perception_group = GroupAction([
        LogInfo(msg='[predator_bringup] Starting perception nodes...'),

        Node(
            package='predator_perception',
            executable='target_tracker_node',
            name='target_tracker',
            output='screen',
            parameters=[cfg('perception.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),

        Node(
            package='predator_perception',
            executable='velocity_estimator_node',
            name='velocity_estimator',
            output='screen',
            parameters=[cfg('perception.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),

        Node(
            package='predator_perception',
            executable='zone_monitor_node',
            name='zone_monitor',
            output='screen',
            parameters=[cfg('zones.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),
    ])

    # ─────────────────────────────────────────────────────────────────────
    # 2. BEHAVIOR
    # ─────────────────────────────────────────────────────────────────────
    behavior_group = GroupAction([
        LogInfo(msg='[predator_bringup] Starting behavior nodes...'),

        Node(
            package='predator_behavior',
            executable='behavior_manager_node',
            name='behavior_manager',
            output='screen',
            parameters=[cfg('behavior.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),

        Node(
            package='predator_behavior',
            executable='safety_supervisor_node',
            name='safety_supervisor',
            output='screen',
            parameters=[cfg('safety.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),
    ])

    # ─────────────────────────────────────────────────────────────────────
    # 3. NAVIGATION
    # ─────────────────────────────────────────────────────────────────────
    navigation_group = GroupAction([
        LogInfo(msg='[predator_bringup] Starting navigation nodes...'),

        Node(
            package='predator_navigation',
            executable='pursuit_planner_node',
            name='pursuit_planner',
            output='screen',
            parameters=[cfg('navigation.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),

        # TODO: uncomment when Nav2 map + params are ready
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource([
        #         PathJoinSubstitution([
        #             FindPackageShare('nav2_bringup'), 'launch', 'bringup_launch.py'
        #         ])
        #     ]),
        #     launch_arguments={
        #         'map': PathJoinSubstitution([bringup_share, 'maps', 'arena.yaml']),
        #         'use_sim_time': use_sim_time,
        #         'params_file': cfg('nav2_params.yaml'),
        #     }.items(),
        # ),
    ])

    # ─────────────────────────────────────────────────────────────────────
    # 4. MANIPULATION
    # ─────────────────────────────────────────────────────────────────────
    manipulation_group = GroupAction([
        LogInfo(msg='[predator_bringup] Starting manipulation nodes...'),

        Node(
            package='predator_manipulation',
            executable='arm_gesture_node',
            name='arm_gesture',
            output='screen',
            parameters=[cfg('manipulation.yaml'), {'use_sim_time': use_sim_time}],
            arguments=['--ros-args', '--log-level', log_level],
        ),

        # TODO: uncomment when UR3 hardware/driver is confirmed
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource([
        #         PathJoinSubstitution([
        #             FindPackageShare('ur_robot_driver'), 'launch', 'ur_control.launch.py'
        #         ])
        #     ]),
        #     launch_arguments={
        #         'ur_type': 'ur3',
        #         'robot_ip': '192.168.1.100',   # TODO: set real UR3 IP
        #         'use_sim_time': use_sim_time,
        #     }.items(),
        # ),
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource([
        #         PathJoinSubstitution([
        #             FindPackageShare('ur_moveit_config'), 'launch', 'ur_moveit.launch.py'
        #         ])
        #     ]),
        #     launch_arguments={
        #         'ur_type': 'ur3',
        #         'use_sim_time': use_sim_time,
        #     }.items(),
        # ),
    ])

    return LaunchDescription([
        use_sim_time_arg,
        log_level_arg,
        perception_group,
        behavior_group,
        navigation_group,
        manipulation_group,
    ])
