#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int out = nums[0], cur = 0;
        for (auto i : nums)
        {
            cur = max(cur+i, i);
            out = max(cur, out);
        }
        return out;
    }
};