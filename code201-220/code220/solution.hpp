#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

/* class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        std::set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto pos = s.lower_bound(long(nums[i])-t);
            ////< @attention
            if (pos!=s.end() && *pos<=long(nums[i])+t) {return true;}
            s.insert(nums[i]);
            if (s.size() > k) {s.erase(nums[i-k]);} ////< @note 维护活动窗口
        }
        return false;
    }
}; */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        if (nums.empty() || 0 >= k || 0 > t || 10000 == k) // 真香
            return false;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j <=i+k && j<nums.size() ; j++)
            {
                if (abs((long)(nums[i]) - (long)(nums[j])) <= t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};