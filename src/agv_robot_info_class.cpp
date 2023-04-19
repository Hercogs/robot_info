#include "hydraulic_system_monitor.cpp"
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
  HydraulicSystemMonitor hydraulic_sytem_agent;
};

// ###############################
// Function defintion for AGVRobotInfo

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

  // Call HydraulicSystemMonitor class constructor
  hydraulic_sytem_agent = HydraulicSystemMonitor();
}

inline void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg_tmpl;

  msg_tmpl.data_field_01 = "robot_description: " + this->robot_description;
  msg_tmpl.data_field_02 = "serial_number: " + this->serial_number;
  msg_tmpl.data_field_03 = "ip_address: " + this->ip_address;
  msg_tmpl.data_field_04 = "firmware_version: " + this->firmware_version;
  msg_tmpl.data_field_05 =
      "maximum_payload: " + std::to_string(this->maximum_payload) + " Kg";

  // Store hydraulic system info
  std::string temperature =
      this->hydraulic_sytem_agent.get_hydraulic_oil_temperature();
  std::string tank_fill_level =
      this->hydraulic_sytem_agent.get_hydraulic_oil_tank_fill_level();
  std::string oil_pressure =
      this->hydraulic_sytem_agent.get_hydraulic_oil_pressure();

  msg_tmpl.data_field_06 = "hydraulic_oil_temperature: " + temperature + "C";
  msg_tmpl.data_field_07 =
      "hydraulic_oil_tank_fill_level: " + tank_fill_level + "%";
  msg_tmpl.data_field_08 = "hydraulic_oil_pressure: " + oil_pressure + " bar";

  pub.publish(msg_tmpl);
}

// Deconstructor
inline AGVRobotInfo::~AGVRobotInfo() {
  ROS_INFO("Class AGVRobotInfo destroyed!");
}