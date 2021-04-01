#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/* class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
}; */

/* class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que; // idx num; large -> small
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (que.size() > 0 && nums[que.back()] < nums[i]) {
                que.pop_back();
            } 
            que.push_back(i);
        }
        res.push_back(nums[que.front()]);
        for (int i = k; i < nums.size(); i++) {
            while (que.size() > 0 && nums[que.back()] < nums[i])
                que.pop_back();
            que.push_back(i);
            while (i - que.front() >= k)
                que.pop_front();
            res.push_back(nums[que.front()]);
        }
        return res;
    }
}; */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < k - 1; i++) {
            que.push(make_pair(nums[i], i));
        }

        vector<int> res;
        for (int i = k - 1; i < nums.size(); i++) {
            que.push(make_pair(nums[i], i));
            while (i - que.top().second >= k) {
                que.pop();
            }
            res.push_back(que.top().first);
        }
        return res;
    }
};