#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)   return 0;
        auto itr = max_element(nums.begin(), nums.end());
        int max_value = *itr;
        *itr = 0;
        int sec_value = *max_element(nums.begin(), nums.end());
        *itr = max_value;
        if (max_value >= (sec_value<<2)) {
            return distance(nums.begin(), itr);
        }
        return -1;
    }
};