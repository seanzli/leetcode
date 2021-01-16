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
    bool hasPathSum(TreeNode* root, int sum) {
        int count = 0;
        return recursion(root, count, sum);
    }

    bool recursion(TreeNode* root, int count, int sum){
        if (root==nullptr)
            return false;
        count = count + root->val;
        if ((count == sum) && (root->left==nullptr) && (root->right == nullptr))  
            return true;
        return (recursion(root->left, count, sum) || recursion(root->right, count, sum));
    }
};