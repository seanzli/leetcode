#include <cstdio>
#include <iostream>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> out;
        if (root == nullptr)    return out;
        queue<TreeNode*> m_que;
        m_que.push(root);
        while (m_que.size()){
            int n = m_que.size();
            int max_value = INT_MIN;
            for (int i = 0 ; i < n; i++){
                TreeNode *cur = m_que.front(); m_que.pop();
                max_value = max(max_value, cur->val);
                if (cur->left)
                    m_que.push(cur->left);
                if (cur->right)
                    m_que.push(cur->right);
            }
            out.push_back(max_value);
        }
        return out;
    }
};