#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/* class Solution {
public:
    bool isValid(string s) {
        int pos = 0;
        while ((pos = s.find("abc")) != s.npos) {
            s.replace(pos, 3, "");
        }
        return s.size() == 0;
    }
}; */

class Solution {
public:
    bool isValid(string s) {
        stack<char> m_stack;
        for (char cur : s) {
            if (cur == 'a' || cur == 'b')
                m_stack.push(cur);
            else {
                if (m_stack.size() < 2)
                    return false;
                if (m_stack.top() == 'b')
                    m_stack.pop();
                else
                    return false;
                if (m_stack.top() == 'a')
                    m_stack.pop();
                else
                    return false;
            }
        }
        return m_stack.size() == 0;
    }
};