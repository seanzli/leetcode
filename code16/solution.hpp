#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <math.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int l,r,n=nums.size(),cur=0,cur_target=INT_MAX;
        for (int i = 0; i < nums.size()-2; i++){
            if (i>0 && nums[i]==nums[i-1])
                continue;

            l=i+1;r=n-1;
            while (l<r){
                cur = nums[i]+nums[l]+nums[r];
                if (cur==target)
                    return target;
                if ((fabs(cur*1.0-target*1.0)<fabs(cur_target*1.0-target*1.0)))
                    cur_target = cur;
                if (cur<target)
                {
                    while ((l<r)&&(nums[l]==nums[l+1]))
                        l++;
                    l++;
                }
                else
                {
                    while ((l<r)&&(nums[r]==nums[r-1]))
                        r--;
                    r--;
                }
            }
        }
        return cur_target;
    }
};