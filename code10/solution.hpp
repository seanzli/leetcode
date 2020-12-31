#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool findMatch(string &s, string &p) {
        
        char *p1 = (char*)s.c_str(), *p2 = (char*)p.c_str();
        char cur = '\0';
        int idx1 = 0, idx2 = 0;
        for (; idx1<s.size() & idx2<p.size();)
        {
            if (p1[idx1]==p2[idx2])
            {
                cur = p2[idx2];
                idx1++;
                idx2++;
                continue;
            }
            
            if (p2[idx1] == '.')
            {
                cur = '.';
                idx1++;
                idx2++;
                continue;
            }

            if (p2[idx1] == '*')
            {
                if (cur == '.')
                {
                    idx1++;
                    continue;
                }
                if (p1[idx1] == cur)
                {
                    idx1++;
                    continue;
                }
                else
                {
                    idx2++;
                    continue;
                }
            }
            
            idx2++;
            
        }
        
        if (idx1==s.size())
        {
            return true;
        }
        return false;
    }
};