#pragma once
#include "core.hpp"

struct Calibration{double wheelRadius,trackWidth,ticksPerRevolution;};
Pose encoder_update(Pose pose,double leftTicks,double rightTicks,const Calibration&calibration);
std::vector<std::pair<double,double>> read_ticks(const std::string&filename);
