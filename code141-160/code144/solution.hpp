#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return out;
    }

    void preorder(TreeNode* root){
        if (root==nullptr)
            return;
        out.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return;
    }
};