#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if (strs.size() == 0)
            return -1;
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){return a.size() > b.size();});

        for (int i = 0; i < strs.size(); i++) {
            int j = 0;
            for (j = 0; j < strs.size(); j++) {
                if (i == j)
                    continue;
                if (strs[i].size() > strs[j].size())
                    return strs[i].size();
                if (isSub(strs[i], strs[j]))
                    break;
            }
            if (j == strs.size())
                return strs[i].size();
        }
        return -1;
    }
    bool isSub(const string& a, const string &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == a.size();
    }
};