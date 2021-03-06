#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }

            while (!s.empty() && nums[i] > nums[s.top()]) {
                v[s.top()] = nums[i];
                s.pop();
            }

            s.push(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                v[s.top()] = nums[i];
                s.pop();
            }
        }

        while (!s.empty()) {
            v[s.top()] = -1;
            s.pop();
        }

        return v;
    }
};