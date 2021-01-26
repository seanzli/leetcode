#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int out = 0;
        int signal = 1;
        int idx = 0;
        out = calc(s, idx);
        return out;
    }

    int calc(string &s, int &idx){
        int out=0, cur=0;
        int signal = 1;
        for (; idx < s.size(); idx++)
        {
            if (s[idx] == '('){
                idx++;
                out += (signal*calc(s, idx));
                signal = 1;
            }
            else if (s[idx]==')'){
                return out += (signal*cur);
            }
            else if (s[idx]=='+'){
                out += (signal*cur);
                cur=0;
                signal = 1;
            }
            else if (s[idx]=='-'){
                out += (signal*cur);
                cur=0;
                signal = -1;
            }
            else if (s[idx]==' ')
                continue;
            else
                cur = cur*10 -'0' + s[idx];
        }
        return out += (signal*cur);
    }
};