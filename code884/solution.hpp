#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hash;
        string cur = "";
        for (char i : A) {
            if (i == ' ') {
                if (cur.size() > 0)
                    hash[cur]++;
                cur = "";
            } else {
                cur += i;
            }
        }
        if (cur.size() > 0)
            hash[cur]++;

        cur = "";
        for (char i : B) {
            if (i == ' ') {
                if (cur.size() > 0)
                    hash[cur]++;
                cur = "";
            } else {
                cur += i;
            }
        }
        if (cur.size() > 0)
            hash[cur]++; 
        
        vector<string> res;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            if (itr->second == 1)
                res.push_back(itr->first);
        }
        return res;
    }
};