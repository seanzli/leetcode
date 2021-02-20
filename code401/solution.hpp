#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
private:
    vector<string> out;
    vector<bool> hour_valid, min_valid;
public:
    vector<string> readBinaryWatch(int num) {
        hour_valid = vector<bool>(4, false);
        min_valid = vector<bool>(6, false);
        gen(0, 0, num);
        return out;
    }
    
    void gen(int cur, int idx, int max) {
        //terminor
        if (idx > 10)
            return;
        if (cur == max) {
            int hour = 0;
            for (bool i : hour_valid) {
                hour <<= 1;
                if (i == true) {
                    hour |= 1;
                }
            }
            if (hour > 11)
                return;
            int min = 0;
            for (bool i : min_valid) {
                min <<= 1;
                if (i == true)
                    min |= 1;
            }
            if (min > 59)
                return;
            string str_min = to_string(min);
            if (str_min.size() == 1)
                str_min = "0" + str_min;
            string str = to_string(hour) + ":" + str_min;
            out.push_back(str);
        }
        
        //process
        for ( ; idx < 10; idx++) {
            if (idx < 4) {
                hour_valid[idx] = true;
            } else {
                min_valid[idx - 4] = true;
            }
            gen(cur + 1, idx + 1, max);
            if (idx < 4) {
                hour_valid[idx] = false;
            } else {
                min_valid[idx - 4] = false;
            }
        }
        return ;
    }
};