#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        double out = 0.0;
        char *p = (char*)s.c_str();
        int start_idx = 0;
        int is_nagitive = -1;
        for (start_idx = 0; start_idx < s.size(); start_idx++)
        {
            if (p[start_idx]=='+')
            {
                is_nagitive = -1;
                start_idx++;
                break;
            }
            if (p[start_idx]=='-')
            {
                is_nagitive = 1;
                start_idx++;
                break;
            }
            if (p[start_idx]==' ')
                continue;
            if ((p[start_idx]>='0')&&(p[start_idx]<='9'))
                break;
            return 0;
        }
        for (; start_idx < s.size(); start_idx++)
        {
            if ((p[start_idx]>='0')&&(p[start_idx]<='9'))
                out = out*10+p[start_idx]-'0';
            else
                break;
        }

        out =is_nagitive*(-1)*out;

        if (out>=INT_MAX)
            return INT_MAX;
        if (out <= INT_MIN)
            return INT_MIN;
        
        return (int)(out);
    }
};