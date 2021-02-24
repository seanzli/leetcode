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
private:
    vector<TreeNode*> m_vec;
    vector<int> res;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        orderFindTarget(root, target);
        int size = m_vec.size();
        for (int i = 0; i < size; i++) {
            TreeNode* cur = m_vec[size - 1 - i];
            getLevelValue(cur, i, K - i);
        }
        return res;
    }

    void orderFindTarget(TreeNode* root, TreeNode* target){
        if (root == nullptr)    return;
        m_vec.push_back(root);
        orderFindTarget(root->left, target);
        orderFindTarget(root->right, target);
        if (m_vec.back()->val == target->val)   return;
        m_vec.pop_back();
    }

    void getLevelValue(TreeNode* root, int cur_node, int level) {
        queue<TreeNode*> que;
        if (root == nullptr)    return;
        que.push(root);
        TreeNode *node = nullptr;
        if (cur_node > 0) node = m_vec[m_vec.size() - cur_node];
        while (que.size() > 0 && level > 0) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = que.front(); que.pop();
                if (cur->left && cur->left != node)
                    que.push(cur->left);
                if (cur->right && cur->right != node)
                    que.push(cur->right);
            }
            level--;
        }
        while (que.size() && level == 0) {
            res.push_back(que.front()->val);
            que.pop();
        }
    }
};