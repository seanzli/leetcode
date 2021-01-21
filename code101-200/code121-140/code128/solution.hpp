#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums) {
        vector<pair<int,int>> gap;
        if (nums.size()<1)
            return 0;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int max_length = 0;
        int cur_idx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i]-nums[i-1]>1)
            {
                max_length = max(max_length, (i-cur_idx));
                cur_idx = i;
            }
        }
        return  max(max_length, ((int)(nums.size())-cur_idx));
    }
};