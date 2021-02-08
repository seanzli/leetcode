#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_value = max(1-nums[0], 1);
        for (int i=1 ;i<nums.size(); i++){
            nums[i] += nums[i-1];
            if (nums[i] <= 0)
                min_value = max(min_value, (int)(ceil((1-nums[i]))));
        }
        return min_value;
    }
};