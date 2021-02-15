#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_ang = 360.0/60.0*minutes;
        double hour_ang = ((hour%12) + minutes*1.0/60.0)*(360.0/12.0);
        double out = max(hour_ang, min_ang) - min(hour_ang,min_ang);
        return out > 180 ? 360 - out : out;
    }
};