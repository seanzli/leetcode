#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        nums.push_back(1);
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int cur = 0;
        while (nums.size()<n){
            cur = min(min(nums[idx2]*2, nums[idx3]*3), nums[idx5]*5);
            if (cur == nums[idx2]*2)
                idx2++;
            if (cur == nums[idx3]*3)
                idx3++;
            if (cur == nums[idx5]*5)
                idx5++;
            nums.push_back(cur);
        }
        return nums.back();
    }
};