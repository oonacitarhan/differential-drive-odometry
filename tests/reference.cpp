#include "core.hpp"
void require(bool ok){if(!ok)throw std::runtime_error("self-test failed");}
int main(){
    constexpr double eps=1e-10;
    double pi=std::acos(-1);
    auto straight=integrate({},1,1,.5);
    require(std::abs(straight.x-1)<eps && std::abs(straight.y)<eps);
    auto spin=integrate({},-.25,.25,.5);
    require(std::abs(spin.x)<eps&&std::abs(spin.y)<eps&&std::abs(spin.heading-1)<eps);
    auto arc=integrate({},0,pi/2,1);
    require(std::abs(arc.x-.5)<eps&&std::abs(arc.y-.5)<eps);
    Pose circle;
    for(int i=0;i<100;++i)circle=integrate(circle,0,2*pi/100,1);
    require(std::hypot(circle.x,circle.y)<eps);
    bool rejected=false;
    try{integrate({},1,1,0);}catch(const std::invalid_argument&){rejected=true;}
    require(rejected);
    std::cout<<"Quarter circle: "<<arc.x<<", "<<arc.y<<", "<<arc.heading<<"\nSelf-tests passed\n";
}
