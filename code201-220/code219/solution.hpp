#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int min_target = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(nums[i])!= hash.end()){
                min_target = min(i-hash[nums[i]], min_target);
                if (min_target <= k)
                    return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};