#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <regex>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int start = 0, end = s.size()-1;
        char end_cha = s[end];
        string temp = s;
        int idx = -1;
        while((idx=s.find(end_cha,idx+1))!=end)
        {
            string s_temp = s.substr(0,idx+1);
            if (isPattern(s, s_temp))
                return true;
        }
        return false;
    }
    bool isPattern(string &s, string &pattern){
        regex re(pattern);
        vector<string> out(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
        for (string i : out){
            if (i.size()>0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};