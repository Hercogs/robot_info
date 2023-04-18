#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>
#include <string>

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle &nh, std::string robot_description,
            std::string serial_number, std::string ip_address,
            std::string firmware_version);
  RobotInfo(){};

  ~RobotInfo();

  virtual void publish_data(); // for publishing data

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  ros::Publisher pub; // Publisher

private:
  ros::NodeHandle *nh;
};

// ###############################
// Function defintion for RobotInfo

// Constructor
inline RobotInfo::RobotInfo(ros::NodeHandle &nh, std::string robot_description,
                            std::string serial_number, std::string ip_address,
                            std::string firmware_version) {
  ROS_INFO("Class RobotInfo created!");

  this->nh = &nh;

  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;

  // Create publisher
  pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 3);
}

inline void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg_tmpl;

  msg_tmpl.data_field_01 = "robot_description: " + this->robot_description;
  msg_tmpl.data_field_02 = "serial_number: " + this->serial_number;
  msg_tmpl.data_field_03 = "ip_address: " + this->ip_address;
  msg_tmpl.data_field_04 = "firmware_version: " + this->firmware_version;

  this->pub.publish(msg_tmpl);
}

// Deconstructor
inline RobotInfo::~RobotInfo() { ROS_INFO("Class RobotInfo destroyed!"); }
