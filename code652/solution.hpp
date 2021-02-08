#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* class Solution {
    vector<TreeNode*> m_vec;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        order(root);
        vector<TreeNode*> out;
        for (int i = 1; i < m_vec.size(); i++){
            for (int j=i+1; j<m_vec.size(); j++){
                if (isSameTree(m_vec[i], m_vec[j])){
                    int idx = 0;
                    for ( ; idx<out.size(); idx++){
                        if (isSameTree(m_vec[i], out[idx]))
                            break;
                    }
                    if (idx == out.size())
                        out.push_back(m_vec[i]);
                }
            }
        }
        return out;
    }
    void order(TreeNode* root){
        if (root == nullptr)
            return;
        m_vec.push_back(root);
        order(root->left);
        order(root->right);
        return;
    }
    bool isSameTree(TreeNode* a, TreeNode* b){
        if (a==nullptr && b==nullptr)   return true;
        if (a==nullptr || b==nullptr)   return false;
        if (a->val == b->val && 
            isSameTree(a->left, b->left) && 
            isSameTree(a->right, b->right))
            return true;
        return false;
    }
}; */

class Solution {
    unordered_map<string, int> save;
    vector<TreeNode*> out;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return out;
    }
    string dfs(TreeNode* root){
        if (root == nullptr)    return ",";
        string str = to_string(root->val) + "," + dfs(root->left)+","+ dfs(root->right);
        save[str]++;
        if (save[str]==2)
            out.push_back(root);
        return str;
    }
};