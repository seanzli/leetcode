#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct node {
        vector<int> nums;
        node(int i, int j) {
            nums.push_back(i);
            nums.push_back(j);
        }
        friend bool operator<(const node& a, const node& b) {
            return (a.nums[0] + a.nums[1]) < (b.nums[0] + b.nums[1]);
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node> que;
        for (int i : nums1) {
            for (int j : nums2) {
                que.push(node(i,j));
                if (que.size() > k)
                    que.pop();
            }
        }

        vector<vector<int>> res;
        while (que.size() > 0) {
            res.push_back(que.top().nums);
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};