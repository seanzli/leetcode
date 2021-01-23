#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int sum = 0, max_sum = 0;
        int start = 0, end = 0;
        int n = nums.size();
        while (end < n){
            if (map.find(nums[end]) == map.end()){
                sum+=nums[end];
                max_sum = max(sum, max_sum);
                map[nums[end]]++;
                end++;
            }
            else {
                map.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
        }
        return max_sum;
    }
};