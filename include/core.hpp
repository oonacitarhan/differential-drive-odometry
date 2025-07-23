#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cmath>

struct Pose { double x=0,y=0,heading=0; };
Pose integrate(Pose pose,double left,double right,double track);
