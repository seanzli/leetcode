#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out = {-1,-1};
        if (nums.size()<1)
            return out;
        if (nums.size()==1)
        {
            if (nums[0]==target)
                return {0,0};
            else
                return out;
        }
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
        if (nums[start] == target)
            mid = start;
        else if (nums[end] == target)
            mid = end;
        if (nums[mid] == target)
        {
            out[0] = mid;
            out[1] = mid;
            int i; 
            for (i= mid-1; i >= 0; i--)
            {
                if (nums[i]!=target)
                    break;
                else
                    out[0] = i;
                
            }
            for (int i = mid+1; i <nums.size(); i++)
            {
                if (nums[i]!=target)
                    break;
                else
                    out[1] = i;
            }
            return out;
        }
        return out;
    }
};