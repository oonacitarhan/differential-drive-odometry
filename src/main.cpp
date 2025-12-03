#include "analysis.hpp"
int main(int argc,char**argv){
    try{
        if(argc!=5)throw std::invalid_argument("usage: odometry_cli LOG WHEEL_RADIUS TRACK_WIDTH TICKS_PER_REV");
        Calibration c={std::stod(argv[2]),std::stod(argv[3]),std::stod(argv[4])};Pose pose;
        std::cout<<"step,x,y,heading\n";int step=0;
        for(auto[left,right]:read_ticks(argv[1])){pose=encoder_update(pose,left,right,c);
            std::cout<<++step<<","<<pose.x<<","<<pose.y<<","<<pose.heading<<"\n";}
    }catch(const std::exception&e){std::cerr<<e.what()<<"\n";return 2;}
}
