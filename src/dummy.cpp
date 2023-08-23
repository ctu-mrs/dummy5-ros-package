#include <ros/ros.h>
#include <nodelet/nodelet.h>

namespace dummy
{

class Dummy : public nodelet::Nodelet {

public:
  virtual void onInit();

private:
  ros::NodeHandle nh_;
};

void Dummy::onInit() {

  ros::NodeHandle nh_ = nodelet::Nodelet::getMTPrivateNodeHandle();

  ros::Time::waitForValid();

  ROS_INFO_THROTTLE(1.0, "[Dummy]: initialized 7");
}

//}

}  // namespace dummy

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(dummy::Dummy, nodelet::Nodelet)
