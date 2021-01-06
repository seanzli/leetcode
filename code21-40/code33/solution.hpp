#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()<1)
            return -1;
        if (nums.size()==1)
        {
            if (nums[0]==target)
                return 0;
            else
                return -1;
        }
        int end = nums.size()-1;
        int mid = end/2;
        int start = 0;
        while ((end-start)>1)
        {
            if (nums[mid]>=nums[start]) //start - mid ascending order
            {
                if ((nums[start] <= target) && (nums[mid] >= target))
                {
                    return check(nums, target, start, mid);
                }
                else
                {
                    start = mid;
                    mid = (end + start)/2;
                }
            }
            else
            {
                if ((nums[mid] <= target) && (target <= nums[end])) 
                {
                    return check(nums, target, mid, end);
                }
                else
                {
                    end = mid;
                    mid = (start + end)/2;
                }
            }
        }
        if (nums[start] == target)
        {
            return start;
        }
        if (nums[end] == target)
        {
            return end;
        }
        return -1;
    }
    int check(vector<int> &nums, int target, int start, int end)
    {
        int mid = (start + end)/2;
        while ((end-start)>1)
        {
            if (nums[mid]<target)
                start = mid;
            else if (nums[mid]>target)
                end = mid;
            else
                return mid;
            mid = (start + end)/2;
        }

        if (end - start <=1)
        {
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            return -1;
        } 
        return -1;
    }
};