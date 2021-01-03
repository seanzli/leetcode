#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
public:
    int char2int(char i)
    {
        switch(i)
        {
            case '(': return -1;
            case '[': return -2;
            case '{': return -3;
            case ')': return 1;
            case ']': return 2;
            case '}': return 3;
            default: return 1000;
        }
    }
    bool isValid(string s) {
        char *p = (char*)s.c_str();
        stack<int> num;
        num.push(char2int(p[0]));
        int cur = 0;
        for (int i = 1; i < s.size(); i++)
        {
            cur = char2int(p[i]);
            if (cur<0)
                num.push(cur);
            else
            {
                if (num.empty())
                    return false;
                if (cur+num.top()==0)
                    num.pop();
                else
                    return false;
            }
        }
        if (num.size()==0)
            return true;
        return false;
    }
};