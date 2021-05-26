#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* class Solution {
public:
    string reverseParentheses(string s) {
        int idx = 0;
        return reverseParentheses(s, idx);
    }

    string reverseParentheses(string s, int& idx) {
        string res = "";
        for (; idx < s.size(); idx++) {
            if (s[idx] == ')')
                return res;
            else if (s[idx] == '(') {
                string cur = reverseParentheses(s, ++idx);
                reverse(cur.begin(), cur.end());
                res += cur;
            } else {
                res += s[idx];
            }
        }
        return res;
    }
}; */

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        int n = s.size();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                 stk.push(i);
            }
            else if (s[i] == ')') {
                pair[stk.top()] = i;
                pair[i] = stk.top();
                stk.pop();
            } else {
                continue;
            }
        }

        int idx = 0, step = 1;
        while (idx < n) {
            if (s[idx] == '(' || s[idx] == ')') {
                idx = pair[idx];
                step = -step;
            } else {
                res.push_back(s[idx]);
            }
            idx += step;
        }
        return res;
    }
};