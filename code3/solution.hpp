#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int max_s=0;
        char *p = (char*)s.c_str();
        int idx = 0;
        for (int i = 0; i < s.size()-max_s; ++i)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (hash.find(p[j])==hash.end())
                {
                    hash.insert(pair<char, int>(p[j],j));
                    ++idx;
                }
                else
                {
                    if (idx > max_s)
                    {
                        max_s = idx;
                    }
                    idx = 0;
                    hash.clear();
                    break;
                }
            }
        }
        if (idx > max_s)
        {
            max_s = idx;
        }
        return max_s;
    }
};