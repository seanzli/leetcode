#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)    return nullptr;
        TreeNode* cur = new TreeNode(root->val);
        if (root->left)
            cur->right = mirrorTree(root->left);
        if (root->right)
            cur->left = mirrorTree(root->right);
        return cur;
    }
};