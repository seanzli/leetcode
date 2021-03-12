#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
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
};