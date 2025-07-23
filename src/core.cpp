#include "core.hpp"

Pose integrate(Pose pose,double left,double right,double track) {
    if(!std::isfinite(track)||track<=0||!std::isfinite(left)||!std::isfinite(right))
        throw std::invalid_argument("finite wheel increments and positive track required");
    double angle=(right-left)/track;
    double distance=(left+right)/2;
    double half=angle/2;
    double scale=std::abs(half)<1e-8 ? 1-half*half/6 : std::sin(half)/half;
    pose.x+=distance*scale*std::cos(pose.heading+half);
    pose.y+=distance*scale*std::sin(pose.heading+half);
    pose.heading=std::remainder(pose.heading+angle,2*std::acos(-1));
    return pose;
}