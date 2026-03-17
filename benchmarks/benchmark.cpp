#include "analysis.hpp"
#include <chrono>
int main(){auto start=std::chrono::steady_clock::now();
Pose pose;for(int i=0;i<100000;++i)pose=integrate(pose,.001,.0011,.5);if(!std::isfinite(pose.x))return 1;
auto elapsed=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
std::cout<<"seconds,"<<elapsed<<"\n";
}
