#include "analysis.hpp"
#include <fstream>
#include <sstream>
Pose encoder_update(Pose pose,double leftTicks,double rightTicks,const Calibration&c){
    if(!std::isfinite(c.wheelRadius)||!std::isfinite(c.ticksPerRevolution)||c.wheelRadius<=0||c.ticksPerRevolution<=0)
        throw std::invalid_argument("positive finite wheel radius and encoder resolution required");
    double distancePerTick=2*std::acos(-1)*c.wheelRadius/c.ticksPerRevolution;
    return integrate(pose,leftTicks*distancePerTick,rightTicks*distancePerTick,c.trackWidth);
}
std::vector<std::pair<double,double>> read_ticks(const std::string&filename){
    std::ifstream f(filename);if(!f)throw std::runtime_error("cannot open encoder log");
    std::vector<std::pair<double,double>> result;std::string line;
    while(std::getline(f,line)){
        if(line.empty()||line[0]=='#')continue;
        std::replace(line.begin(),line.end(),',',' ');std::istringstream stream(line);
        double left,right;std::string extra;
        if(!(stream>>left>>right)||(stream>>extra))throw std::invalid_argument("expected two numeric increments per row");
        result.emplace_back(left,right);
    }
    return result;
}
