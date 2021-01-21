#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
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
    int maxDepth(TreeNode* root) {
        int out = 0;
        if (root == nullptr)
            return out;
        out = getDepth(root, out);
        return out;
    }
    int getDepth(TreeNode* root, int out){
        if (root == nullptr)
            return out;
        out++;
        return (max(getDepth(root->left, out), getDepth(root->right, out)));
    }
};