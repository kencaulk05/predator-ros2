#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "predator_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__BehaviorState() -> *const std::ffi::c_void;
}

#[link(name = "predator_msgs__rosidl_generator_c")]
extern "C" {
    fn predator_msgs__msg__BehaviorState__init(msg: *mut BehaviorState) -> bool;
    fn predator_msgs__msg__BehaviorState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BehaviorState>, size: usize) -> bool;
    fn predator_msgs__msg__BehaviorState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BehaviorState>);
    fn predator_msgs__msg__BehaviorState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BehaviorState>, out_seq: *mut rosidl_runtime_rs::Sequence<BehaviorState>) -> bool;
}

// Corresponds to predator_msgs__msg__BehaviorState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// BehaviorState.msg
/// Published by: behavior_manager_node
/// Consumed by: pursuit_planner_node, arm_gesture_node, safety_supervisor_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BehaviorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Current behavior state (use constants above)
    pub state: u8,

    /// Human-readable state name for debugging
    pub state_label: rosidl_runtime_rs::String,

    /// Seconds spent in current state
    pub time_in_state: f32,

    /// Why the last state transition occurred
    pub transition_reason: rosidl_runtime_rs::String,

}

impl BehaviorState {
    /// State enum constants
    pub const SEARCH: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ACQUIRE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PURSUIT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const HERD: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ARM_ALERT: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SAFETY_STOP: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REACQUIRE: u8 = 6;

}


impl Default for BehaviorState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !predator_msgs__msg__BehaviorState__init(&mut msg as *mut _) {
        panic!("Call to predator_msgs__msg__BehaviorState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BehaviorState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__BehaviorState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__BehaviorState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__BehaviorState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BehaviorState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BehaviorState where Self: Sized {
  const TYPE_NAME: &'static str = "predator_msgs/msg/BehaviorState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__BehaviorState() }
  }
}


#[link(name = "predator_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__GestureRequest() -> *const std::ffi::c_void;
}

#[link(name = "predator_msgs__rosidl_generator_c")]
extern "C" {
    fn predator_msgs__msg__GestureRequest__init(msg: *mut GestureRequest) -> bool;
    fn predator_msgs__msg__GestureRequest__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GestureRequest>, size: usize) -> bool;
    fn predator_msgs__msg__GestureRequest__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GestureRequest>);
    fn predator_msgs__msg__GestureRequest__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GestureRequest>, out_seq: *mut rosidl_runtime_rs::Sequence<GestureRequest>) -> bool;
}

// Corresponds to predator_msgs__msg__GestureRequest
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// GestureRequest.msg
/// Published by: behavior_manager_node
/// Consumed by: arm_gesture_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GestureRequest {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Requested gesture (use constants above)
    pub gesture_type: u8,

    /// Used by GESTURE_POINT: world-frame target
    pub target_point: geometry_msgs::msg::rmw::Point,

    /// Motion speed scale
    pub urgency: f32,

}

impl GestureRequest {
    /// Gesture type enum constants
    pub const GESTURE_NONE: u8 = 0;

    /// "Ready" tracking posture
    pub const GESTURE_READY: u8 = 1;

    /// Point toward predicted intercept location
    pub const GESTURE_POINT: u8 = 2;

    /// Freeze / safety retreat posture
    pub const GESTURE_FREEZE: u8 = 3;

    /// Return to home/neutral position
    pub const GESTURE_RESET: u8 = 4;

}


impl Default for GestureRequest {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !predator_msgs__msg__GestureRequest__init(&mut msg as *mut _) {
        panic!("Call to predator_msgs__msg__GestureRequest__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GestureRequest {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__GestureRequest__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__GestureRequest__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__GestureRequest__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GestureRequest {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GestureRequest where Self: Sized {
  const TYPE_NAME: &'static str = "predator_msgs/msg/GestureRequest";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__GestureRequest() }
  }
}


#[link(name = "predator_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__TargetState() -> *const std::ffi::c_void;
}

#[link(name = "predator_msgs__rosidl_generator_c")]
extern "C" {
    fn predator_msgs__msg__TargetState__init(msg: *mut TargetState) -> bool;
    fn predator_msgs__msg__TargetState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TargetState>, size: usize) -> bool;
    fn predator_msgs__msg__TargetState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TargetState>);
    fn predator_msgs__msg__TargetState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TargetState>, out_seq: *mut rosidl_runtime_rs::Sequence<TargetState>) -> bool;
}

// Corresponds to predator_msgs__msg__TargetState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// TargetState.msg
/// Published by: target_tracker_node, velocity_estimator_node
/// Consumed by: behavior_manager_node, pursuit_planner_node, safety_supervisor_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TargetState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Current estimated pose in map frame
    pub pose: geometry_msgs::msg::rmw::PoseStamped,

    /// Estimated linear + angular velocity
    pub velocity: geometry_msgs::msg::rmw::TwistStamped,

    /// Short-horizon predicted position
    pub predicted_pose: geometry_msgs::msg::rmw::PoseStamped,

    /// Tracking confidence
    pub confidence: f32,

    /// True if target is actively tracked
    pub is_tracked: bool,

    /// Euclidean distance from robot base
    pub distance_to_robot: f32,

}



impl Default for TargetState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !predator_msgs__msg__TargetState__init(&mut msg as *mut _) {
        panic!("Call to predator_msgs__msg__TargetState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TargetState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__TargetState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__TargetState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__TargetState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TargetState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TargetState where Self: Sized {
  const TYPE_NAME: &'static str = "predator_msgs/msg/TargetState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__TargetState() }
  }
}


#[link(name = "predator_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__ZoneStatus() -> *const std::ffi::c_void;
}

#[link(name = "predator_msgs__rosidl_generator_c")]
extern "C" {
    fn predator_msgs__msg__ZoneStatus__init(msg: *mut ZoneStatus) -> bool;
    fn predator_msgs__msg__ZoneStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ZoneStatus>, size: usize) -> bool;
    fn predator_msgs__msg__ZoneStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ZoneStatus>);
    fn predator_msgs__msg__ZoneStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ZoneStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<ZoneStatus>) -> bool;
}

// Corresponds to predator_msgs__msg__ZoneStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ZoneStatus.msg
/// Published by: zone_monitor_node
/// Consumed by: behavior_manager_node, arm_gesture_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ZoneStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// True if target is within UR3 interaction region
    pub target_in_ur3_zone: bool,

    /// True if target is within minimum safe distance
    pub target_in_safety_zone: bool,

    /// Distance from target to UR3 zone center
    pub distance_to_zone_center: f32,

    /// Configured radius of the UR3 interaction zone
    pub zone_radius: f32,

    /// Center of the UR3 interaction zone in map frame
    pub zone_center: geometry_msgs::msg::rmw::Point,

}



impl Default for ZoneStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !predator_msgs__msg__ZoneStatus__init(&mut msg as *mut _) {
        panic!("Call to predator_msgs__msg__ZoneStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ZoneStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__ZoneStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__ZoneStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { predator_msgs__msg__ZoneStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ZoneStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ZoneStatus where Self: Sized {
  const TYPE_NAME: &'static str = "predator_msgs/msg/ZoneStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__predator_msgs__msg__ZoneStatus() }
  }
}


