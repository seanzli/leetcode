#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* class Solution {
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
}; */

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> order;
        string temp = "";
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') {
                order.push_back(temp);
                temp = "";
            } else {
                temp += preorder[i];
            }
        }
        if (temp.size())
            order.push_back(temp);

        if (order[0] == "#")
            return order.size() == 1;
        int count = 2;
        int i = 1;
        for (i = 1; i < order.size(); i++) {
            if (order[i] == "#") {
                count--;
                if (count < 0)
                    return false;
                if (count == 0)
                    break;
            }
            else {
                count++;
            }
        }
        return count == 0 && i == order.size() - 1;
    }
};