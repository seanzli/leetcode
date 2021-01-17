#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_list;
        for (auto i : wordDict)
            word_list.insert(i);
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j< i; j++)
            {
                if (dp[j] && word_list.find(s.substr(j, i - j)) != word_list.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};