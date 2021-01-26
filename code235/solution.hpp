#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *out = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        order(root, min(p->val, q->val), max(p->val, q->val));
        return out;
    }
    void order(TreeNode*root, int p, int q){
        if (root == nullptr)
            return;
        if ((root->val <=q) && (root->val >= p)){
            out = root;
            return;
        }

        if (root->val > q)
            order(root->left, p, q);
        else if (root->val < p)
            order(root->right, p, q);
        return;
    }
};