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

//class Solution {
//public:
//    bool isEvenOddTree(TreeNode* root) {
//        queue<TreeNode*> m_que;
//        int idx = 0;
//        m_que.push(root);
//        int min_value = 0, max_value = INT_MAX;
//        while (m_que.size())
//        {
//            int n = m_que.size();
//            for (int i = 0; i < n; i++)
//            {
//                TreeNode* cur = m_que.front();
//                m_que.pop();
//                if (cur->val % 2 == idx) // odd or even check
//                    return false;
//                if (idx == 0){  // increase;
//                    if (cur->val <= min_value)
//                        return false;
//                    min_value = cur->val;
//                } else {
//                    if (cur->val >= max_value)
//                        return false;
//                    max_value = cur->val;
//                }
//                if (cur->left)
//                    m_que.push(cur->left);
//                if (cur->right)
//                    m_que.push(cur->right);
//            }
//            min_value = 0, max_value = INT_MAX;
//            idx = 1 - idx;
//        }
//
//        return true;
//    }
//};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr)
            return true;
        que.push(root);
        bool flag = true;
        while (!que.empty()) {
            int n = que.size();
            vector<int> cur;
            for (int i = 0; i < n; ++i) {
                TreeNode* t = que.front(); que.pop();
                cur.push_back(t->val);
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
            if (flag && even(cur)) { // level even, number all odd and increase
                flag = !flag;
                continue;
            } else if ((!flag) && odd(cur)) {
                flag = !flag;
                continue;
            }
            return false;
        }

        return true;
    }

    // level odd, number should be all even and decrease.
    bool odd(const vector<int>& vec) {
        if (vec.empty())
            return true;
        if ((vec[0] & 0x1) == 1)
            return false;
        for (int i = 1; i < vec.size(); ++i) {
            if (((vec[i] & 0x1) == 1) || (vec[i] >= vec[i-1]))
                return false;
        }
        return true;
    }
    bool even(const vector<int>& vec) {
        if (vec.empty())
            return true;
        if ((vec[0] & 0x1) == 0)
            return false;
        for (int i = 1; i < vec.size(); ++i) {
            if (((vec[i] & 0x1) == 0) || (vec[i] <= vec[i-1]))
                return false;
        }
        return true;
    }
};