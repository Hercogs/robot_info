#include "agv_robot_info_class.cpp"
#include "ros/duration.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  std::string robot_description = "Mir100";
  std::string serial_number = "567A359";
  std::string ip_address = "169.254.5.180";
  std::string firmware_version = "3.5.8";
  int maximum_payload = 100;

  AGVRobotInfo my_agv_robot(nh, robot_description, serial_number, ip_address,
                     firmware_version, maximum_payload);

  while (ros::ok()) {
    ros::Duration(1).sleep();
    my_agv_robot.publish_data();
  }

  return 0;
}