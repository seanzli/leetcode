#include <cstdio>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](string s1, string s2){
            int p1 = s1.find(' '), p2 = s2.find(' ');
            bool f1 = isalpha(s1[p1 + 1]), f2 = isalpha(s2[p2 + 1]);
            if(f1 && !f2) return true;
            if(f1 && f2){
                return pair{s1.substr(p1), s1.substr(0, p1)} < pair{s2.substr(p2), s2.substr(0, p2)};
            }
            return false;
        });
        return logs;
    }
};