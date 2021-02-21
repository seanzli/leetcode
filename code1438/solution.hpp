#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queMax, queMin;
        int n = nums.size();
        int left = 0, right = 0;
        int ret = 0;
        while (right < n) {
            while (!queMax.empty() && queMax.back() < nums[right]) {
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back() > nums[right]) {
                queMin.pop_back();
            }
            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit) {
                if (nums[left] == queMin.front()) {
                    queMin.pop_front();
                }
                if (nums[left] == queMax.front()) {
                    queMax.pop_front();
                }
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m_set;
        int left = 0;
        int max_length = 0;
        for (int right = 0; right < nums.size(); right++) {
            m_set.insert(nums[right]);
            while (*m_set.rbegin() - *m_set.begin() > limit) {
                m_set.erase(m_set.find(nums[left++]));
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};