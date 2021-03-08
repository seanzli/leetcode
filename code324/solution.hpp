#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/* class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> large;

        if (nums.size() == 1)
            return;
        if (nums[0] > nums[1]) {
            small.push(nums[1]);
            large.push(nums[0]);
        } else {
            small.push(nums[0]);
            large.push(nums[1]);
        }

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] <= small.top()) {
                small.push(nums[i]);
            } else {
                large.push(nums[i]);
            }

            while (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            }

            while (large.size() > small.size()) {
                small.push(large.top());
                large.pop();
            }
        }

        nums.clear();
        vector<int> large_list(large.size());
        int i = 0;
        while (large.size()) {
            large_list[i++] = large.top();
            large.pop();
        }
        while (small.size()) {
            nums.push_back(small.top());
            small.pop();
            if (large_list.size()) {
                nums.push_back(large_list.back());
                large_list.pop_back();
            }
        }
        return ;        
    }
}; */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> res = nums;
        sort(res.begin(), res.end());
        int small_idx = (res.size() - 1) / 2;
        int largt_idx = res.size() - 1;
        int i = 0;
        while (small_idx >= 0) {
            nums[i++] = res[small_idx--];
            nums[i++] = res[largt_idx--];
        }
    }
};