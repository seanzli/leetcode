#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* class Solution {
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
}; */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0)
            return res;
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        stack<int> st; // small -> large
        res = vector<int>(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (st.size() > 0 && nums[st.top()] < nums[i]) {
                if (st.top() < n)
                    res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};