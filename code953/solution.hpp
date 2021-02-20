#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for (int i = 0; i < order.size(); i++) {
            hash[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int idx = 0;
            for ( ; idx < words[i].size() && idx < words[i + 1].size(); idx++) {
                if (hash[words[i][idx]] > hash[words[i + 1][idx]])
                    return false;
                if (hash[words[i][idx]] < hash[words[i + 1][idx]])
                    break;
            }
            if (idx == min(words[i].size(), words[i + 1].size()) && words[i + 1].size() < words[i].size()) {
                return false;
            }
        }
        return true;
    }
};