#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        string str_num = "";
        for (char cur : str) {
            if (cur >= '0' && cur <= '9')
                str_num += cur;
            else if (cur == '+' || cur == '-')
                str_num += cur;
            else if (cur == ' ') {
                if (str_num.size() > 0)
                    break;
                else
                    continue;
            }
            else
                break;
        }
        double out = atof(str_num.c_str());
        if (out > INT_MAX)
            return INT_MAX;
        if (out < INT_MIN)
            return INT_MIN;
        return (int)(out);
    }
};