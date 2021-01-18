#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> out;
        for (auto i : tokens)
        {
            if (i == "+"){
                int a = out.top(); out.pop();
                int b = out.top(); out.pop();
                out.push(a+b);
            }
            else if (i == "-"){
                int a = out.top(); out.pop();
                int b = out.top(); out.pop();
                out.push(a-b);
            }
            else if (i == "*"){
                int a = out.top(); out.pop();
                int b = out.top(); out.pop();
                out.push(a*b);
            }
            else if (i == "/"){
                int a = out.top(); out.pop();
                int b = out.top(); out.pop();
                out.push(b/a);
            }
            else
            {
                out.push(atoi(i.c_str()));
            }
            
        }
        return out.top();
    }
};