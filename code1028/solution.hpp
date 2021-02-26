#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode * root = nullptr;
        queue<pair<int, TreeNode*>> que;
        decode(S, que);
        root = preorder(que, 0);
        return root;
    }
    void decode(string s, queue<pair<int, TreeNode*>>& que) {
        string num = "";
        int level = 0;
        int flag = 1; //1 -> work for num, 0 = work for level;
        for (char cur : s) {
            if (flag == 1) {
                if (cur == '-') {
                    que.push(make_pair(level, new TreeNode(atoi(num.c_str()))));
                    level = 1;
                    flag = 0;
                    num = "";
                } else {
                    num += cur;
                }
            } else {
                if (cur == '-') {
                    level++;
                } else {
                    flag = 1;
                    num = cur;
                }
            }
        }
        if (num.size())
            que.push(make_pair(level, new TreeNode(atoi(num.c_str()))));
        return;
    }
    TreeNode* preorder(queue<pair<int, TreeNode*>>& que, int level) {
        if (que.size() == 0)    return nullptr;
        auto itr = que.front();
        if (itr.first != level) return nullptr;
        que.pop();
        itr.second->left = preorder(que, level + 1);
        itr.second->right = preorder(que, level + 1);
        return itr.second;
    }
};