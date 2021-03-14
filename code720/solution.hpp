#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    struct Tire {
        bool isEnd;
        vector<Tire*> child;
        Tire() {
            isEnd = false;
            child = vector<Tire*>(26, nullptr);
        };
    };
public:
    string longestWord(vector<string>& words) {
        Tire* root = new Tire();
        for (string str : words) {
            Tire* cur = root;
            for (char i : str) {
                if (cur->child[i - 'a'] == nullptr)
                    cur->child[i - 'a'] = new Tire();
                cur = cur->child[i - 'a'];
            }
            cur->isEnd = true;
        }

        string res = "";
        string cur = "";
        dfs(root, res, cur);
        return res;
    }

    void dfs(Tire* root, string& res, string& cur) {
        for (int i = 0; i < 26; ++i) {
            if (root->child[i] == nullptr)
                continue;
            if (root->child[i]->isEnd == true) {
                cur += (i + 'a');
                dfs(root->child[i], res, cur);
                if (res.size() < cur.size()) {
                    res = cur;
                }
                cur.pop_back();
            }
        }
    }
};