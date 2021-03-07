#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> a = coordinates[0];
        vector<int> b = coordinates[1];
        vector<int> dif(2, 0), dif2(2, 0);
        dif[0] = a[0] - b[0];
        dif[1] = a[1] - b[1];
        for (int i = 2; i < coordinates.size(); i++) {
            dif2[0] = a[0] - coordinates[i][0];
            dif2[1] = a[1] - coordinates[i][1];
            if (checkVector(dif, dif2) == false)
                return false;
        }
        return true;
    }
    bool checkVector(vector<int> a, vector<int> b) {
        double a_length = sqrt(a[0]*a[0] + a[1]*a[1]);
        double b_length = sqrt(b[0]*b[0] + b[1]*b[1]);

        double a1 = a[0] * 1.0 / a_length;
        double a2 = a[1] * 1.0 / a_length;
        double b1 = b[0] * 1.0 / b_length;
        double b2 = b[1] * 1.0 / b_length;
        if (a1 * b1 < 0 || a2 * b2 < 0) {
            a1 *= -1.0;
            a2 *= -1.0;
        }
        if (abs(a1 - b1) < 1e-6 && abs(a2 - b2) < 1e-6)
            return true;
        return false;
    }
};