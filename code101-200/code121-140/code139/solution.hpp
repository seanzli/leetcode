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

/* class Solution {
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
}; */

/* class Solution {
    struct Tirl{
        bool isEnd;
        vector<Tirl*> child;
        Tirl() {
            isEnd = false;
            child = vector<Tirl*>(26, nullptr);
        }
    };
    Tirl* dict = nullptr;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = new Tirl();
        for (int i = 0; i < wordDict.size(); i++) {
            Tirl* cur = dict;
            for (int j = 0; j < wordDict[i].size(); j++) {
                if (cur->child[wordDict[i][j] - 'a'] == nullptr)
                    cur->child[wordDict[i][j] - 'a'] = new Tirl();
                cur = cur->child[wordDict[i][j] - 'a'];
            }
            cur->isEnd = true;
        }

        return dfs(s, 0, dict);
    }

    bool dfs(const string& s, int idx, Tirl* root) {
        if (idx == s.size()) {
            return root->isEnd;
        }

        if (root->isEnd && dfs(s, idx, dict))
            return true;
        
        return root->child[s[idx] - 'a'] && dfs(s, idx + 1, root->child[s[idx] - 'a']);
    }
}; */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (string str : wordDict)
            hash.insert(str);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && hash.find(s.substr(j, i - j)) != hash.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};