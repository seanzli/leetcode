#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <math.h>

using namespace std;

class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double tx = 2.0;
        double ty = 2.0;
        while (tx * tx + ty * ty > 1) {
            tx = 2 * (double)rand() / RAND_MAX - 1;
            ty = 2 * (double)rand() / RAND_MAX - 1;
        }
        return {x + tx * r, y + ty * r};
    }
};
