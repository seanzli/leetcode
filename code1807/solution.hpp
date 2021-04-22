#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for (auto itr : knowledge)
            hash["(" + itr[0] + ")"] = itr[1];
        
        string res = "";
        int left = 0;
        bool flag = true;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '(') {
                left = right;
                flag = false;
            } else if (s[right] == ')') {
                string cur = s.substr(left, right - left + 1);
                flag = true;
                if (hash.find(cur) != hash.end())
                    res += hash[cur];
                else
                    res += "?";
            } else if (flag) {
                res += s[right];
            }
        }
        return res;
    }
};