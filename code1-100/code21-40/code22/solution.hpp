#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        dfs(cur, 0, 0, n);
        return res;
    }
    void dfs(string& cur, int left, int right, int n) {
        if (left + right == 2*n) {
            res.push_back(cur);
            return;
        }
        if (left < n) {
            cur += '(';
            dfs(cur, left + 1, right, n);
            cur.pop_back();
        }
        if (right < left) {
            cur += ')';
            dfs(cur, left, right + 1, n);
            cur.pop_back();
        }
        return;
    }
};