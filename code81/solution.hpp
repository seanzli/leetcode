#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        while (start<= end)
        {
            mid = (start+end)/2;
            if (nums[mid]==target)
                return true;
            
            if (nums[start] < nums[mid])
            {
                if (nums[start] <= target && target <= nums[mid])
                    end = mid;
                else
                    start = mid;
            }
            else if (nums[mid] < nums[start])
            {
                if (nums[mid] <= target && target <= nums[end])
                    start = mid;
                else
                    end = mid;
            }
            else if (nums[mid] == nums[start])
                start++;
        }
        return false;
    }
};