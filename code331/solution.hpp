#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int idx = 0;
        validPreorder(preorder, idx);
        return idx == preorder.size() + 1;
    }

    void validPreorder(const string& preorder, int& idx) {
        if (idx == -1)
            return;
        if (idx == preorder.size() + 1) {
            idx = -1;
            return;
        }
        if (getValue(preorder, idx) == "#") {
            return;
        }
        validPreorder(preorder, idx);
        validPreorder(preorder, idx);
        return;
    }

    string getValue(const string& str, int& idx) {
        string res = "";
        for (; idx<str.size(); idx++) {
            if (str[idx] == ',')
                break;
            res += str[idx];
        }
        idx++;
        return res;
    }
};