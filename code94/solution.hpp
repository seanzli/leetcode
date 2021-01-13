#include <cstdio>
#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

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
    vector<int> out;
    vector<int> inorderTraversal(TreeNode* root) {
        out.clear();
        getRootValue(root);
        return out;
    }
    void getRootValue(TreeNode *root){
        if (root)
        {
            out.push_back(root->val);
            getRootValue(root->left);
            getRootValue(root->right);
        }
        return;
    }
};