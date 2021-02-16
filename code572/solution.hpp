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
    string s_str, t_str;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        s_str = ",";
        t_str = ",";
        dfs(s, s_str);
        dfs(t, t_str);
        return s_str.find(t_str)==s_str.npos;
    }
    void dfs(TreeNode* root, string &out){
        if (root == nullptr){
            out += ",";
            return;
        }
        out += (to_string(root->val) +",");
        dfs(root->left, out);
        dfs(root->right, out);
        return;
    }
};