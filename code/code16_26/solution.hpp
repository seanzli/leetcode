#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        const unordered_set<char> signs{'+', '-', '*', '/'};
        stack<int> ss;
        char sign = '+';
        int num = 0;
        int topVal = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + (s[i]-'0');
            }
            if (signs.find(s[i]) != signs.end() || i == n-1)
            {
                if (sign == '+')
                {
                    ss.push(num);
                }
                else if (sign == '-')
                {
                    ss.push(-num);
                }
                else if (sign == '*')
                {
                    topVal = ss.top();
                    ss.pop();
                    ss.push(topVal * num);
                }
                else
                {
                    topVal = ss.top();
                    ss.pop();
                    ss.push(topVal / num);
                }
                num = 0;
                sign = s[i];
            }
        }

        int res = 0;
        while (!ss.empty())
        {
            res += ss.top();
            ss.pop();
        }
        return res;
    }
};