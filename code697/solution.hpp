#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        int max_count = 0, min_length = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = {1, i, i};
            }
            else {
                hash[nums[i]][0]++;
                hash[nums[i]][2] = i;
            }
        }
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            if (max_count < itr->second[0]) {
                min_length = itr->second[2] - itr->second[1] + 1;
                max_count = itr->second[0];
            } else if (max_count == itr->second[0]) {
                min_length = min(min_length, itr->second[2] - itr->second[1] + 1);
            }
        }
        return min_length;
    }
};