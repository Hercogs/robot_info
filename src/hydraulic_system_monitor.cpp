#include <string>

class HydraulicSystemMonitor {

public:
  std::string get_hydraulic_oil_temperature();
  std::string get_hydraulic_oil_tank_fill_level();
  std::string get_hydraulic_oil_pressure();

private:
  std::string hydraulic_oil_temperature = "45";
  std::string hydraulic_oil_tank_fill_level = "100";
  std::string hydraulic_oil_pressure = "250";
};

// ##############
// Class HydraulicSystemMonitor function definition

inline std::string HydraulicSystemMonitor::get_hydraulic_oil_temperature() {
  return this->hydraulic_oil_temperature;
}

inline std::string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() {
  return this->hydraulic_oil_tank_fill_level;
}

inline std::string HydraulicSystemMonitor::get_hydraulic_oil_pressure() {
  return this->hydraulic_oil_pressure;
}
