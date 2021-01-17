#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>

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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        inorder(root);
        return max_sum;
    }

    int inorder(TreeNode* root){
        if (root == nullptr)
            return 0;

        int left_max = max(inorder(root->left),0);
        int right_max = max(inorder(root->right),0);
        int cur = root->val + left_max + right_max;
        
        max_sum = max(max_sum, cur);

        return root->val + max(left_max, right_max);
    }
};