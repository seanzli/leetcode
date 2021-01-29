#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> m_que;
        int idx = 0;
        m_que.push(root);
        int min_value = 0, max_value = INT_MAX;
        while (m_que.size())
        {
            int n = m_que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* cur = m_que.front();
                m_que.pop();
                if (cur->val % 2 == idx) // odd or even check
                    return false;
                if (idx == 0){  // increase;
                    if (cur->val <= min_value)
                        return false;
                    min_value = cur->val;
                } else {
                    if (cur->val >= max_value)
                        return false;
                    max_value = cur->val;
                }
                if (cur->left)
                    m_que.push(cur->left);
                if (cur->right)
                    m_que.push(cur->right);
            }
            min_value = 0, max_value = INT_MAX;
            idx = 1 - idx;
        }
        
        return true;
    }
};