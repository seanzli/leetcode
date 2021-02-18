#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ) {
            if (nums[i] != nums[i+2])
                return nums[i];
            i += 3;
        }
        return nums.back();
    }
};