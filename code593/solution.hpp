#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (check(p1, p2, p3, p4) && check(p2, p1, p3, p4) && check(p3, p1, p2, p4) && check(p4, p1, p2, p3));
    }
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> dis1;
        dis1.push_back(distance(p1,p2));
        dis1.push_back(distance(p1,p3));
        dis1.push_back(distance(p1,p4));
        sort(dis1.begin(), dis1.end());
        if (dis1[0] < 1e-6)
            return false;
        if (fabs(dis1[0] - dis1[1]) > 1e-6)
            return false;
        if (fabs(dis1[0]*sqrt(2.0) - dis1[2]) > 1e-6)
            return false;
        return true;
    }
    double distance(vector<int>& p1, vector<int>& p2) {
        return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
    }
};