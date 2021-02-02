#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> delSet(to_delete.begin(), to_delete.end());
        if (postOrder(root, delSet, res)) {
            res.push_back(root);
        }
        return res;
    }

private:
    TreeNode* postOrder(TreeNode* root, unordered_set<int>& delSet, vector<TreeNode*>& res) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = postOrder(root->left, delSet, res);
        root->right = postOrder(root->right, delSet, res);
        if (delSet.count(root->val)) {
            if (root->left) {
                res.push_back(root->left);
            }
            if (root->right) {
                res.push_back(root->right);
            }
            return nullptr;
        } else {
            return root;
        }
    }
};