#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <unordered_set>

using namespace std;

/* class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (!wordBreak_139(s, wordDict)) return {};

        size_t validEnd = 0;
        vector<vector<string>> dp(s.size() + 1, vector<string>());

        for (size_t i = 0; i < s.size(); i++) {
            if (i == validEnd + 1) return {};
            if (i != 0 && dp[i].empty()) continue;
            for (auto& word : wordDict) {
                size_t newEnd = i + word.size();
                if (newEnd > s.size()) continue;
                if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
                validEnd = max(validEnd, newEnd);
                if (i == 0) {
                    dp[newEnd].push_back(word);
                    continue;
                }
                for (auto& d : dp[i]) {
                    dp[newEnd].push_back(d + " " + word);
                }
            }
        }

        return dp.back();
    }

    bool wordBreak_139(string& s, vector<string>& wordDict) {
        size_t validEnd = 0;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size(); i++) {
            if (i == validEnd + 1) return false;
            if (!dp[i]) continue;
            for (auto& word : wordDict) {
                size_t newEnd = i + word.size();
                if (newEnd > s.size()) continue;
                if (memcmp(&s[i], &word[0], word.size()) == 0) {
                    dp[newEnd] = true;
                    validEnd = max(validEnd, newEnd);
                }
            }
        }
        return dp.back();
    }
}; */

class Solution {
    unordered_set<string> dict;
    vector<string> res;
    vector<string> cur;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string str : wordDict)
            dict.insert(str);
        dfs(s, 0);
        return res;
    }

    void dfs(const string& s, int idx) {
        if (idx == s.size()) {
            if (cur.size()) {
                string str = "";
                for (int i = 0; i < cur.size(); i++) {
                    str += (cur[i] + " ");
                }
                str.pop_back();
                res.push_back(str);
            }
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (dict.find(s.substr(idx, i - idx + 1)) == dict.end())
                continue;
            cur.push_back(s.substr(idx, i - idx + 1));
            dfs(s, i + 1);
            cur.pop_back();
        }
    }
};