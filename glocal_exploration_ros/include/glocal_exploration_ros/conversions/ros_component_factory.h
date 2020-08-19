#ifndef GLOCAL_EXPLORATION_ROS_CONVERSIONS_ROS_COMPONENT_FACTORY_H_
#define GLOCAL_EXPLORATION_ROS_CONVERSIONS_ROS_COMPONENT_FACTORY_H_

#include <memory>
#include <string>

#include <ros/node_handle.h>

#include <glocal_exploration/state/communicator.h>
#include "glocal_exploration_ros/visualization/local_planner_visualizer_base.h"

namespace glocal_exploration {

class ComponentFactoryROS {
 public:
  virtual ~ComponentFactoryROS() = default;

  static std::shared_ptr<MapBase> createMap(
      const ros::NodeHandle& nh,
      const std::shared_ptr<Communicator>& communicator);

  static std::shared_ptr<LocalPlannerBase> createLocalPlanner(
      const ros::NodeHandle& nh,
      const std::shared_ptr<Communicator>& communicator);

  static std::shared_ptr<LocalPlannerVisualizerBase>
  createLocalPlannerVisualizer(
      const ros::NodeHandle& nh,
      const std::shared_ptr<Communicator>& communicator);

  static std::shared_ptr<RegionOfInterest> createRegionOfInterest(
      const ros::NodeHandle& nh);

 private:
  ComponentFactoryROS() = default;
  static std::string getType(const ros::NodeHandle& nh);
};

}  // namespace glocal_exploration

#endif  // GLOCAL_EXPLORATION_ROS_CONVERSIONS_ROS_COMPONENT_FACTORY_H_
