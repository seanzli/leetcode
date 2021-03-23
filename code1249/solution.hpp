#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> vec;
        stack<int> idx;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                idx.push(i);
            } else if (s[i] == ')') {
                if (idx.size() == 0) {
                    vec.push_back(i);
                } else {
                    idx.pop();
                }
            }
        }
        while (idx.size()) {
            vec.push_back(idx.top());
            idx.pop();
        }
        sort(vec.begin(), vec.end());
        vec.push_back(s.size());
        string res = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == vec[j]) {
                j++;
                continue;
            }
            res += s[i];
        }
        return res;
    }
};