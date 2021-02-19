#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_hash;
        unordered_map<string, int> hash;
        for (string cur : banned) {
            transform(cur.begin(), cur.end(), cur.begin(), ::tolower);
            banned_hash.insert(cur);
        }
        string temp = "";
        for (char i : paragraph) {
            if (isalpha(i))
                temp += i;
            else if (temp.size()) {
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                if (banned_hash.count(temp) == 0)
                    hash[temp]++;
                temp = "";
            }
        }
        if (temp.size()){
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (banned_hash.count(temp) == 0)
                hash[temp]++;
        }
        
        int max_count = 0;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            if (max_count < itr->second) {
                max_count = itr->second;
                temp = itr->first;
            }
        }
        return temp;
    }
};