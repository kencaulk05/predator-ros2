#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to predator_msgs__msg__BehaviorState
/// BehaviorState.msg
/// Published by: behavior_manager_node
/// Consumed by: pursuit_planner_node, arm_gesture_node, safety_supervisor_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BehaviorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Current behavior state (use constants above)
    pub state: u8,

    /// Human-readable state name for debugging
    pub state_label: std::string::String,

    /// Seconds spent in current state
    pub time_in_state: f32,

    /// Why the last state transition occurred
    pub transition_reason: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BehaviorState::default())
  }
}

impl rosidl_runtime_rs::Message for BehaviorState {
  type RmwMsg = super::msg::rmw::BehaviorState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state,
        state_label: msg.state_label.as_str().into(),
        time_in_state: msg.time_in_state,
        transition_reason: msg.transition_reason.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      state: msg.state,
        state_label: msg.state_label.as_str().into(),
      time_in_state: msg.time_in_state,
        transition_reason: msg.transition_reason.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state,
      state_label: msg.state_label.to_string(),
      time_in_state: msg.time_in_state,
      transition_reason: msg.transition_reason.to_string(),
    }
  }
}


// Corresponds to predator_msgs__msg__GestureRequest
/// GestureRequest.msg
/// Published by: behavior_manager_node
/// Consumed by: arm_gesture_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GestureRequest {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Requested gesture (use constants above)
    pub gesture_type: u8,

    /// Used by GESTURE_POINT: world-frame target
    pub target_point: geometry_msgs::msg::Point,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GestureRequest::default())
  }
}

impl rosidl_runtime_rs::Message for GestureRequest {
  type RmwMsg = super::msg::rmw::GestureRequest;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        gesture_type: msg.gesture_type,
        target_point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.target_point)).into_owned(),
        urgency: msg.urgency,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      gesture_type: msg.gesture_type,
        target_point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.target_point)).into_owned(),
      urgency: msg.urgency,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      gesture_type: msg.gesture_type,
      target_point: geometry_msgs::msg::Point::from_rmw_message(msg.target_point),
      urgency: msg.urgency,
    }
  }
}


// Corresponds to predator_msgs__msg__TargetState
/// TargetState.msg
/// Published by: target_tracker_node, velocity_estimator_node
/// Consumed by: behavior_manager_node, pursuit_planner_node, safety_supervisor_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TargetState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Current estimated pose in map frame
    pub pose: geometry_msgs::msg::PoseStamped,

    /// Estimated linear + angular velocity
    pub velocity: geometry_msgs::msg::TwistStamped,

    /// Short-horizon predicted position
    pub predicted_pose: geometry_msgs::msg::PoseStamped,

    /// Tracking confidence
    pub confidence: f32,

    /// True if target is actively tracked
    pub is_tracked: bool,

    /// Euclidean distance from robot base
    pub distance_to_robot: f32,

}



impl Default for TargetState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TargetState::default())
  }
}

impl rosidl_runtime_rs::Message for TargetState {
  type RmwMsg = super::msg::rmw::TargetState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        velocity: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
        predicted_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.predicted_pose)).into_owned(),
        confidence: msg.confidence,
        is_tracked: msg.is_tracked,
        distance_to_robot: msg.distance_to_robot,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        velocity: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
        predicted_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.predicted_pose)).into_owned(),
      confidence: msg.confidence,
      is_tracked: msg.is_tracked,
      distance_to_robot: msg.distance_to_robot,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.pose),
      velocity: geometry_msgs::msg::TwistStamped::from_rmw_message(msg.velocity),
      predicted_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.predicted_pose),
      confidence: msg.confidence,
      is_tracked: msg.is_tracked,
      distance_to_robot: msg.distance_to_robot,
    }
  }
}


// Corresponds to predator_msgs__msg__ZoneStatus
/// ZoneStatus.msg
/// Published by: zone_monitor_node
/// Consumed by: behavior_manager_node, arm_gesture_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ZoneStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// True if target is within UR3 interaction region
    pub target_in_ur3_zone: bool,

    /// True if target is within minimum safe distance
    pub target_in_safety_zone: bool,

    /// Distance from target to UR3 zone center
    pub distance_to_zone_center: f32,

    /// Configured radius of the UR3 interaction zone
    pub zone_radius: f32,

    /// Center of the UR3 interaction zone in map frame
    pub zone_center: geometry_msgs::msg::Point,

}



impl Default for ZoneStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ZoneStatus::default())
  }
}

impl rosidl_runtime_rs::Message for ZoneStatus {
  type RmwMsg = super::msg::rmw::ZoneStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        target_in_ur3_zone: msg.target_in_ur3_zone,
        target_in_safety_zone: msg.target_in_safety_zone,
        distance_to_zone_center: msg.distance_to_zone_center,
        zone_radius: msg.zone_radius,
        zone_center: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.zone_center)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      target_in_ur3_zone: msg.target_in_ur3_zone,
      target_in_safety_zone: msg.target_in_safety_zone,
      distance_to_zone_center: msg.distance_to_zone_center,
      zone_radius: msg.zone_radius,
        zone_center: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.zone_center)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      target_in_ur3_zone: msg.target_in_ur3_zone,
      target_in_safety_zone: msg.target_in_safety_zone,
      distance_to_zone_center: msg.distance_to_zone_center,
      zone_radius: msg.zone_radius,
      zone_center: geometry_msgs::msg::Point::from_rmw_message(msg.zone_center),
    }
  }
}


