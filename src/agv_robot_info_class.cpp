#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle &nh, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, int maximum_payload);
  ~AGVRobotInfo();

  void publish_data(); // for publishing data

protected:
  int maximum_payload;

private:
};

// Constructor
inline AGVRobotInfo::AGVRobotInfo(ros::NodeHandle &nh,
                                  std::string robot_description,
                                  std::string serial_number,
                                  std::string ip_address,
                                  std::string firmware_version,
                                  int maximum_payload)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version) {

  ROS_INFO("Class AGVRobotInfo created!");
  this->maximum_payload = maximum_payload;
}

inline void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg_tmpl;

  msg_tmpl.data_field_01 = "robot_description: " + this->robot_description;
  msg_tmpl.data_field_02 = "serial_number: " + this->serial_number;
  msg_tmpl.data_field_03 = "ip_address: " + this->ip_address;
  msg_tmpl.data_field_04 = "firmware_version: " + this->firmware_version;
  msg_tmpl.data_field_05 =
      "maximum_payload: " + std::to_string(this->maximum_payload) + " Kg";

  pub.publish(msg_tmpl);
}

// Deconstructor
inline AGVRobotInfo::~AGVRobotInfo() {
  ROS_INFO("Class AGVRobotInfo destroyed!");
}