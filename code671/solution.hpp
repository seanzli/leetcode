/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-07-27 21:43:10
 * @LastEditTime: 2021-07-27 21:54:13
 * @LastEditors: Sean
 * @Reference: 
 */

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
    int ans = -1;
    int rootvalue;
public:
    int findSecondMinimumValue(TreeNode* root) {
        rootvalue = root->val;
        dfs(root);
        return ans == rootvalue ? -1 : ans;
    }
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        if (ans != -1 && node->val >= ans) {
            return;
        }
        if (node->val > rootvalue) {
            ans = node->val;
        }
        dfs(node->left);
        dfs(node->right);
    }
};