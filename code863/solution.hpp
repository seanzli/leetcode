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

// class Solution {
// private:
//     vector<TreeNode*> m_vec;
//     vector<int> res;
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         orderFindTarget(root, target);
//         int size = m_vec.size();
//         for (int i = 0; i < size; i++) {
//             TreeNode* cur = m_vec[size - 1 - i];
//             getLevelValue(cur, i, K - i);
//         }
//         return res;
//     }

//     void orderFindTarget(TreeNode* root, TreeNode* target){
//         if (root == nullptr)    return;
//         m_vec.push_back(root);
//         orderFindTarget(root->left, target);
//         orderFindTarget(root->right, target);
//         if (m_vec.back()->val == target->val)   return;
//         m_vec.pop_back();
//     }

//     void getLevelValue(TreeNode* root, int cur_node, int level) {
//         queue<TreeNode*> que;
//         if (root == nullptr)    return;
//         que.push(root);
//         TreeNode *node = nullptr;
//         if (cur_node > 0) node = m_vec[m_vec.size() - cur_node];
//         while (que.size() > 0 && level > 0) {
//             int n = que.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* cur = que.front(); que.pop();
//                 if (cur->left && cur->left != node)
//                     que.push(cur->left);
//                 if (cur->right && cur->right != node)
//                     que.push(cur->right);
//             }
//             level--;
//         }
//         while (que.size() && level == 0) {
//             res.push_back(que.front()->val);
//             que.pop();
//         }
//     }
// };

//class Solution {
//    vector<TreeNode*> path;
//    vector<int> res;
//    TreeNode* cur = nullptr;
//public:
//    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//        getPath(root, target->val);
//        while (k >= 0 && path.size() > 0) {
//            getValue(path.back(), k);
//            cur = path.back();
//            path.pop_back();
//            k--;
//        }
//        return res;
//    }
//
//    bool getPath(TreeNode* node, int val) {
//        if (node == nullptr)
//            return false;
//        path.push_back(node);
//        if (node->val == val)
//            return true;
//        if (getPath(node->left, val) == true || getPath(node->right, val) == true)
//            return true;
//        path.pop_back();
//        return false;
//    }
//
//    void getValue(TreeNode* node, int k) {
//        if (node == nullptr)
//            return;
//        if (k == 0) {
//            res.push_back(node->val);
//            return;
//        }
//        if (cur != node->left)
//            getValue(node->left, k - 1);
//        if (cur != node->right)
//            getValue(node->right, k - 1);
//        return;
//    }
//};

class Solution {
    vector<TreeNode*> path;
    vector<int> res;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target);
        TreeNode* cur = nullptr;
        while (k >= 0 && path.size() > 0) {
            distance(path.back(),cur, k);
            cur = path.back();
            path.pop_back();
            k--;
        }
        return res;
    }

private:
    bool dfs(TreeNode* root, TreeNode* target) {
        if (root == nullptr)
            return false;
        path.push_back(root);
        if (root == target
            || dfs(root->left, target)
            || dfs(root->right, target)
            )
            return true;
        path.pop_back();
        return false;
    }

    void distance(TreeNode* node, TreeNode* avoid, int k) {
        if (node == nullptr || node == avoid)
            return;
        if (k == 0) {
            res.push_back(node->val);
            return;
        }
        distance(node->left, avoid,k - 1);
        distance(node->right, avoid, k - 1);
        return;
    }
};