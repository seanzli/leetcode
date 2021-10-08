#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<string,int>mp;
//         vector<string>res;
//         for(int i=0;i+9<s.size();i++){
//             auto key=s.substr(i,10);
//             if(mp[key]==1)res.push_back(key);
//                 mp[key]++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        if (s.size() < 10)
            return {};
        string cur = s.substr(0, 9);
        for (int i = 9; i < s.size(); ++i) {
            cur.push_back(s[i]);
            hash[cur]++;
            cur = cur.substr(1);
        }
        vector<string> res;
        for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
            if (itr->second > 1)
                res.push_back(itr->first);
        }
        return res;
    }
};