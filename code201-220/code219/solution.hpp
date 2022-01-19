#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <limits.h>

using namespace std;

//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        unordered_map<int,int> hash;
//        int min_target = INT_MAX;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (hash.find(nums[i])!= hash.end()){
//                min_target = min(i-hash[nums[i]], min_target);
//                if (min_target <= k)
//                    return true;
//            }
//            hash[nums[i]] = i;
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        int right = 0;
        for (right = 0; right < k; ++right) {
            if (hash.count(nums[right]))
                return true;
            hash.insert(nums[right]);
        }
        for (int left = 0; right < nums.size(); ++right, ++left) {
            if (hash.count(nums[right]))
                return true;
            hash.insert(nums[right]);
            hash.erase(nums[left]);
        }
        return false;
    }
};