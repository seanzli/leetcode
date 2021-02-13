#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum=accumulate(nums.begin(),nums.end(),0)-x,sum=0;
        int left=0,right=0;
        int ans=-1;
        while(right<nums.size()){
            sum+=nums[right];right++;//每次循环右移拉长窗口
            while(left<nums.size()&&sum>totalsum)
                sum-=nums[left],left++;//根据和大小调整窗长，使窗口和小于等于所求值
            if(sum==totalsum)ans=max(ans,right-left);
        }
        return ans==-1?-1:nums.size()-ans;
    }
};