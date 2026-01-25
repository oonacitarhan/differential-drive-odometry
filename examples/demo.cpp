#include "analysis.hpp"
int main(){Pose pose;Calibration c={.0762,.55,2048};
    for(int i=0;i<10;++i){pose=encoder_update(pose,100,120,c);std::cout<<pose.x<<","<<pose.y<<","<<pose.heading<<"\n";}
}
