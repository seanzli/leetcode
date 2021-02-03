#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> out;
        int n = nums.size();
        out.push_back(nums[0]*nums[1]*nums[2]);
        out.push_back(nums[0]*nums[1]*nums[n-1]);
        out.push_back(nums[n-1]*nums[n-2]*nums[n-3]);
        out.push_back(nums[n-1]*nums[n-2]*nums[0]);
        return *max_element(out.begin(), out.end());
    }
};