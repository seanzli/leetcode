#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size()-1;
        int times = 0, longest=0, jump_to = 0, start=0;
        
        if (nums[0]==0)
            return 0;
        if (nums.size()==1)
            return 0;
        
        while (1)
        {
            longest=0, jump_to = 0;
            if (start + nums[start] >= target)
                return times+1;
            
            for (int i = 1; i <= nums[start]; i++)
            {
                if ((nums[start+i]!=0) && (start+i+nums[start+i] > longest))
                {
                    longest = start+i+nums[start+i];
                    jump_to = start+i;
                }
            }
            if (jump_to == 0)
            {
                return 0;
            }
            
            start = jump_to;
            times++;
        }
        return times;
    }
};