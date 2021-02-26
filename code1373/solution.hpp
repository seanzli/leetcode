#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    int value = 0;
public:
    int maxSumBST(TreeNode* root) {
        int cur_value = INT_MIN;
        isBST(root, cur_value);
        return value == INT_MIN ? 0 : value;
    }
    bool isBST(TreeNode* root, int& cur_value) {
        if (root == nullptr) {
            cur_value = 0;
            return true;
        }    
        int left = INT_MIN, right = INT_MIN;
        bool flag_left = isBST(root->left, left);
        bool flag_right = isBST(root->right, right);
        if (flag_left && flag_right) {
            if (root->left != nullptr && root->val <= root->left->val)
                return false;
            if (root->right != nullptr && root->val >= root->right->val)
                return false;
            cur_value = left + right + root->val;
            value = max(value, cur_value);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};
        auto lArr = dfs(root->left);
        auto rArr = dfs(root->right);
        int sum = 0, curmax, curmin;
        if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) {
            return {false, 0, 0, 0};
        }
        curmin = root->left ? lArr[1] : root->val;
        curmax = root->right ? rArr[2] : root->val;
        sum += (root->val + lArr[3] + rArr[3]);
        maxsum = max(maxsum, sum);
        return {true, curmin, curmax, sum};
    }
};