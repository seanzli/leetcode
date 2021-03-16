#include <cstdio>
#include <vector>
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
    vector<int> res;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        if (dfs(root, voyage, idx))
            return res;
        return {-1};
    }
    bool dfs(TreeNode* root, vector<int>& voyage, int& idx) {
        if (root == nullptr)
            return true;
        if (idx == voyage.size())
            return true;
        if (root->val == voyage[idx]) {
            idx++;
            int cur = idx;
            if (false == dfs(root->left, voyage, idx)) {
                TreeNode* left = root->left;
                root->left = root->right;
                root->right = left;
                res.push_back(root->val);
                idx = cur;
                return dfs(root->left, voyage, idx) && dfs(root->right, voyage, idx);
            } else {
                return dfs(root->right, voyage, idx);
            }

        }
        return false;
    }
};