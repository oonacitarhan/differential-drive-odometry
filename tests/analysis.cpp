#include "analysis.hpp"
void need(bool b){if(!b)throw std::runtime_error("encoder regression failed");}
int main(){
    Calibration c={.1,.5,1000};auto p=encoder_update({},1000,1000,c);
    need(std::abs(p.x-2*std::acos(-1)*.1)<1e-12);
    Pose parts;for(int i=0;i<100;++i)parts=encoder_update(parts,5,10,c);
    auto whole=encoder_update({},500,1000,c);
    need(std::hypot(parts.x-whole.x,parts.y-whole.y)<1e-10);
    auto reverse=encoder_update(whole,-500,-1000,c);need(std::hypot(reverse.x,reverse.y)<1e-10);
    bool rejected=false;try{encoder_update({},1,1,{0,.5,1000});}catch(const std::invalid_argument&){rejected=true;}need(rejected);
    std::cout<<"Encoder calibration, subdivision invariance, reverse trajectory and bounds pass\n";
}
