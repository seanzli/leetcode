#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size()<1)
            return 0;

        
        int start = 0, end = nums.size()-1, mid = (start+end)/2;
        while((end-start)>1)
        {
            if (nums[mid]<target)
                start = mid;
            else if (nums[mid]>target)
                end = mid;
            else
                break;
            mid = (start + end)/2;
        }

        if (nums[end]<target)
            return end+1;
        if (nums[mid]<target)
            return end;
        if (nums[start]<target)
            return mid;
        return start;
    }
};