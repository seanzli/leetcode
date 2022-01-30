#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    vector<string> uncommonFromSentences(string A, string B) {
//        unordered_map<string, int> hash;
//        string cur = "";
//        for (char i : A) {
//            if (i == ' ') {
//                if (cur.size() > 0)
//                    hash[cur]++;
//                cur = "";
//            } else {
//                cur += i;
//            }
//        }
//        if (cur.size() > 0)
//            hash[cur]++;
//
//        cur = "";
//        for (char i : B) {
//            if (i == ' ') {
//                if (cur.size() > 0)
//                    hash[cur]++;
//                cur = "";
//            } else {
//                cur += i;
//            }
//        }
//        if (cur.size() > 0)
//            hash[cur]++;
//
//        vector<string> res;
//        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
//            if (itr->second == 1)
//                res.push_back(itr->first);
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hash1, hash2;
        auto vec1 = split(s1);
        auto vec2 = split(s2);

        for (const auto& itr : vec1)
            ++hash1[itr];
        for (const auto& itr : vec2)
            ++hash2[itr];

        vector<string> res;
        for (const auto& itr : hash1) {
            if (itr.second == 1 && hash2.find(itr.first) == hash2.end())
                res.emplace_back(itr.first);
        }
        for (const auto& itr : hash2) {
            if (itr.second == 1 && hash1.find(itr.first) == hash1.end())
                res.emplace_back(itr.first);
        }
        return res;
    }

    vector<string> split(const string& s) {
        regex re(" ");
        return vector<string>(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
    }
};