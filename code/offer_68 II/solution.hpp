#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
        vector<TreeNode*> p_root;
        vector<TreeNode*> q_root;
        vector<TreeNode*> m_vec;
        bool b_find_p = false, b_find_q = false;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)    return nullptr;
        dfs(root, p, q);
        int idx = 0;
        for (; idx < p_root.size() && idx<q_root.size(); idx++){
            if (p_root[idx]->val != q_root[idx]->val)
                break;
        }
        return p_root[idx-1];
    }
    void dfs(TreeNode* root, TreeNode* p, TreeNode *q){
        if (root == nullptr)    return;
        if (b_find_p == false && p->val == root->val){
            p_root = m_vec;
            p_root.push_back(p);
            b_find_p = true;
        }
        if (b_find_q == false && q->val == root->val){
            q_root = m_vec;
            q_root.push_back(q);
            b_find_q = true;
        }
        if (b_find_p && b_find_q)
            return;

        m_vec.push_back(root);
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        m_vec.pop_back();
    }
};