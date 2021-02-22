#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long sum = 0;
        int max_value = pow(10, 9) + 7;
        stack<int> m_stack;
        arr.push_back(0);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (m_stack.size() > 0 && arr[i] <= arr[m_stack.top()]) {
                int index = m_stack.top();
                m_stack.pop();
                int pre_idx = -1;
                if (m_stack.size() > 0)
                    pre_idx = m_stack.top();
                int pre_count = index - pre_idx - 1;
                int next_count = i - index - 1;
                sum += long(arr[index]) * (pre_count + 1) * (next_count + 1) % max_value;
                sum %= max_value;
            }
            m_stack.push(i);
        }
        return sum;
    }
};