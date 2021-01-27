#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_vec(26,0);
        vector<int> t_vec(26,0);
        for (int i = 0; i < s.size(); i++)
        {
            s_vec[s[i]-'a']++;
            t_vec[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (s_vec[i] != t_vec[i])
                return false;
        }
        return true;
    }
};