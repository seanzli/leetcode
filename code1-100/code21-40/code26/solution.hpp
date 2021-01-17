#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<1)
            return 0;
        int cur = nums[0];
        int idx = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i]==cur)
                continue;
            nums[idx] = nums[i];
            cur = nums[i];
            idx++;
        }
        return idx;
    }
};