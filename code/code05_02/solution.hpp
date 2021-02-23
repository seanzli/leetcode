#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        while (res.size() <= 32 && fabs(num) > 1e-6) {
            num *= 2;
            int cur = (int)(floor(num));
            res += to_string(cur);
            num -= cur;
        }
        if (fabs(num) <= 1e-6)
            return res;
        else
            return "ERROR";
    }
};