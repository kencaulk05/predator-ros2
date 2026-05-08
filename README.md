# Predator — Biomimetic Surveillance Robot
### ROS 2 Kilted | CS-150 Intro to ROS2

A Predator-inspired robot system that detects humans via ArUco markers, herds them toward a stationary UR3e robotic arm using a Turtlebot 2 Kobuki, and performs expressive threat gestures when the target enters the interaction zone.

---

## System Overview

```
USB Camera (wall-mounted)
    ↓ ArUco detection
target_tracker_node  →  /target_pose (camera frame)
    ↓
camera_to_map_transform_node  →  /target_pose_map (map frame)
    ↓
behavior_manager_node  →  /behavior_state + /gesture_request
    ↓                              ↓
pursuit_planner_node          arm_gesture_node
    ↓                              ↓
Nav2 → Turtlebot 2           MoveIt → UR3e arm
```

**7-State FSM:** `SEARCH → ACQUIRE → PURSUIT → HERD → ARM_ALERT → SAFETY_STOP → REACQUIRE`

---

## Packages

| Package | Description |
|---|---|
| `predator_msgs` | Custom message definitions |
| `predator_perception` | Camera pipeline, ArUco tracking, coordinate transform, zone detection |
| `predator_behavior` | FSM behavior manager, safety supervisor |
| `predator_navigation` | Pursuit/herd planner using Nav2 |
| `predator_manipulation` | UR3e arm gesture controller using MoveIt |
| `predator_bringup` | Launch files, maps, and configuration |

---

## Hardware Setup

- **Camera:** USB camera mounted at map position (0.0, 1.00, 2.00)m, tilt=30°, yaw=12°
- **UR3e arm:** Map position (0.0, 1.29), facing +X into arena, base height=1.25m
- **Turtlebot 2 Kobuki:** Standby position (2.75, 1.80), facing arm (-X direction)
- **Arena:** Reversed-r shape defined by blue tape, approx 6.1m × 3.5m
- **Lab network:** Lab computer (10.3.13.215, ROS 2 Kilted), Turtlebot laptop (10.5.12.184, ROS 2 Foxy)

---

## Build Instructions

### Prerequisites
- ROS 2 Kilted
- Nav2: `sudo apt install ros-kilted-nav2-bringup`
- SLAM Toolbox: `sudo apt install ros-kilted-slam-toolbox`
- MoveIt: installed via `ros-kilted-moveit`
- CycloneDDS: `sudo apt install ros-kilted-rmw-cyclonedds-cpp`
- v4l2 camera: `sudo apt install ros-kilted-v4l2-camera`
- OpenCV with ArUco: `pip install opencv-contrib-python --break-system-packages`

### Build
```bash
cd ~/Ros2_predator-project_WS
colcon build
source install/setup.bash
```

---

## Launch Instructions

```bash
#Tutorial - Turtlebot 2
documentation link: Turtlebot tutorial: https://docs.google.com/document/d/1Kw_JVrSo9lak-vepSjTjmib_KBXwqYstHOnxjuZmc70/edit?usp=sharing

#Tutorial - Ur3 arm
documentation link: Ur3 tutorial: https://docs.google.com/document/d/1TIIi-UZ_CYYCgizXtyPkHD_mAFIHL6pIckP7bZw3JlU/edit?tab=t.0#heading=h.acsicofp790u
```

### Step 1 — Turtlebot 2 (SSH to turtle-one laptop, ROS 2 Foxy ---> ROS2 Kilted)
```bash
# Terminal 1 — Kobuki base
ros2 launch turtlebot2_bringup kobuki.launch.py

# Terminal 2 — OpenNI depth camera
ros2 launch openni2_camera openni2.launch.py

# Terminal 3 — Static transforms
ros2 run tf2_ros static_transform_publisher 0 0 0.35 0 0 0 base_link camera_link
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 odom base_footprint

# Terminal 4 — Depth to laser scan
ros2 run depthimage_to_laserscan depthimage_to_laserscan_node

# Terminal 5 — Rosbridge
ros2 launch rosbridge_server rosbridge_websocket_launch.xml
```

### Step 2 — SSH Tunnel (lab computer)
```bash
ssh -L 9090:localhost:9090 turtle-one@10.5.12.184
# password: turtle
```

### Step 3 — Turtle Bridge (lab computer)
```bash
python3 ~/turtle_bridge.py
```

### Step 4 — UR3e Arm (lab computer, CycloneDDS terminals)
```bash
# Terminal A
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
ros2 launch ur_robot_driver ur_control.launch.py ur_type:=ur3e robot_ip:=10.3.4.12 launch_rviz:=false
# Press Play on teach pendant

# Terminal B
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
ros2 launch ur_moveit_config ur_moveit.launch.py ur_type:=ur3e robot_ip:=10.3.4.12 launch_rviz:=false
```

### Step 5 — Nav2 (lab computer)
```bash
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 launch nav2_bringup bringup_launch.py \
  use_sim_time:=false \
  params_file:=$HOME//Ros2_predator-project_WS/src/predator_bringup/config/nav2_params.yaml \
  map:=$HOME/Ros2_predator-project_WS/src/predator_bringup/maps/arena_map.yaml
```

### Step 6 — Predator System (lab computer)
```bash
# Terminal 1 — Perception pipeline
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 launch predator_bringup perception.launch.py

# Terminal 2 — Camera to map transform
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 run predator_perception camera_to_map_transform_node

# Terminal 3 — Behavior manager (handwritten node)
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 run predator_behavior behavior_manager_node

# Terminal 4 — Pursuit planner
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 run predator_navigation pursuit_planner_node

# Terminal 5 — Arm gesture node (CycloneDDS)
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
source ~/Ros2_predator-project_WS/install/setup.bash
ros2 run predator_manipulation arm_gesture_node
```

### Step 7 — Set Initial Pose
Place Turtlebot physically at map position (2.75, 1.80) facing the arm, then:
```bash
ros2 topic pub --once /initialpose geometry_msgs/msg/PoseWithCovarianceStamped \
  "{header: {frame_id: 'map'}, pose: {pose: {position: {x: 2.75, y: 1.80, z: 0.0}, \
  orientation: {x: 0.0, y: 0.0, z: 1.0, w: 0.0}}, \
  covariance: [0.25,0,0,0,0,0,0,0.25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.06853]}}"
```

---

## Required Component Links

### MoveIt
UR3e arm gesture execution using MoveGroup action client:
[`src/predator_manipulation/predator_manipulation/arm_gesture_node.py`](src/predator_manipulation/predator_manipulation/arm_gesture_node.py)

### Nav2
Pursuit and herd navigation using navigate_to_pose action:
[`src/predator_navigation/predator_navigation/pursuit_planner_node.py`](src/predator_navigation/predator_navigation/pursuit_planner_node.py)

Nav2 parameters:
[`nav2_params.yaml`](https://github.com/kencaulk05/predator-ros2) *(stored at `~/nav2_params.yaml` on lab computer)*

### Perception
ArUco marker detection and camera-to-map coordinate transform:
- [`src/predator_perception/predator_perception/target_tracker_node.py`](src/predator_perception/predator_perception/target_tracker_node.py)
- [`src/predator_perception/predator_perception/camera_to_map_transform_node.py`](src/predator_perception/predator_perception/camera_to_map_transform_node.py)
- [`src/predator_perception/predator_perception/zone_monitor_node.py`](src/predator_perception/predator_perception/zone_monitor_node.py)

### Custom Components
7-state FSM behavior manager, velocity estimator, zone monitor, pursuit planner, arm gesture controller:
- [`src/predator_behavior/predator_behavior/behavior_manager_node.py`](src/predator_behavior/predator_behavior/behavior_manager_node.py)
- [`src/predator_behavior/predator_behavior/safety_supervisor_node.py`](src/predator_behavior/predator_behavior/safety_supervisor_node.py)
- [`src/predator_perception/predator_perception/velocity_estimator_node.py`](src/predator_perception/predator_perception/velocity_estimator_node.py)
- [`src/predator_msgs/`](src/predator_msgs/) — custom message definitions

### Node Written Entirely By Hand
The behavior manager was written entirely by hand without AI assistance:
[`src/predator_behavior/predator_behavior/behavior_manager_node.py`](src/predator_behavior/predator_behavior/behavior_manager_node.py)

This node implements the full 7-state FSM from scratch, including state transitions, confidence thresholding, zone detection integration, gesture publishing, and safety supervision logic.

---

## Known Issues & Limitations

### Navigation (Nav2 / Turtlebot 2)
The arena has no physical walls — boundaries are defined by blue tape on the floor. This causes two issues:

1. **AMCL localization drift:** The laser scan sees table legs and chairs as obstacles instead of clean walls. AMCL loses track of the robot's position near arena boundaries where the laser scan doesn't match the hand-drawn map.

2. **Nav2 goal rejection (status=6 INVALID_GOAL):** When AMCL loses localization, Nav2 considers the robot's current position to be outside the map's free space and rejects navigation goals. Short-range goals in the center of the corridor work reliably; longer goals toward the arena edges fail.

**Workaround:** The system was constrained to a reduced safe navigation zone (x: 0.30→2.50m, y: 0.40→1.80m). For reliable navigation, a SLAM-generated map should replace the hand-drawn map.

### MoveIt / UR3e
- MoveIt requires `scaled_joint_trajectory_controller` to be active. After launching the UR driver, activate it manually if needed: `ros2 control switch_controllers --activate scaled_joint_trajectory_controller`
- The teach pendant must be in Remote Control mode before launching MoveIt
- POINT gesture updates are rate-limited to 3 seconds to prevent MoveIt overload

### Camera
- ArUco markers (DICT_4X4_50, 0.15m, IDs 0 and 1) must be worn by the target
- The camera loses the marker when the target is closer than ~0.7m to the UR3 arm (outside camera field of view)

---

## Additional Documentation

- **Arena map:** Hand-drawn PGM map at `src/predator_bringup/maps/arena_map.pgm`, resolution 0.05m/px
- **Camera calibration:** Stored at `~/.ros/camera_info/` on lab computer after first run
- **UR3e IP:** Check teach pendant each session (typically 10.3.4.12)
- **Turtlebot WiFi:** tufts_eecs / foundedin1883
- **RMW note:** CycloneDDS (`export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp`) must be active in all terminals communicating with the UR3e. Do NOT set it globally — Nav2 and Turtlebot communication requires the default RMW.
