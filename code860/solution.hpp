#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5 = 0, num_10 = 0;
        for (int i : bills) {
            if (i == 5)
                num_5++;
            else if (i == 10) {
                num_10++;
                if (num_5 > 0)
                    num_5--;
                else
                    return false;
            } else {
                if (num_10 > 0 && num_5 > 0) {
                    num_10--;
                    num_5--;
                } else if (num_5 >= 3) {
                    num_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};