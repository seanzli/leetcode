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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p_vec, q_vec;
        order(root, p_vec, p);
        order(root, q_vec, q);
        for (int i = 0; i < min(p_vec.size(),q_vec.size()); i++)
        {
            if (q_vec[i] != p_vec[i])
                return q_vec[i-1];
        }
        return q_vec[min(p_vec.size(),q_vec.size())-1];
    }

    bool order(TreeNode*root, vector<TreeNode*> &p_vec, TreeNode *p){
        if (root == nullptr) return false;
        p_vec.push_back(root);
        if (root == p){
            return true;
        }
        if (order(root->left,p_vec, p))
            return true;
        if (order(root->right,p_vec, p))
            return true;
        p_vec.pop_back();
        return false;
    }
};