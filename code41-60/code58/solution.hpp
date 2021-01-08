#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string cur;
        
        int i = s.size()-1;
        for (; i>=0; --i)
        {
            if (s[i] == ' ')
                continue;
            else
                break;
        }

        for (int j = i; j>=0; --j)
        {
            if (s[j] == ' ')
                return cur.size();
            cur = cur + s[j];
        }
        return cur.size();
    }
};