#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>
#include <queue>
#include <limits.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> idx_s, idx_t;
        for (int i = 0; i < s.size(); i++)
        {
            if ((idx_s.find(s[i]) == idx_s.end()) && (idx_t.find(t[i]) == idx_t.end())){
                idx_s[s[i]] = i;
                idx_t[t[i]] = i;
            }
            else if ((idx_s.find(s[i]) != idx_s.end()) &&
                     (idx_t.find(t[i]) != idx_t.end()) &&
                     (idx_s[s[i]] == idx_t[t[i]])){
                continue;
            }
            else 
                return false;
        }
        return true;
    }
};