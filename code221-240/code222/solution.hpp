#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

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
    // 统计树的深度
    int countLevels(TreeNode* root) {
        int levels = 0;
        while (root) {
            root = root->left; levels += 1;
        }
        return levels;
    }
    int countNodes(TreeNode* root){
        // 2. 利用完全二叉树性质简化遍历次数
        if(root == nullptr) return 0;
        int left_levels = countLevels(root->left);
        int right_levels = countLevels(root->right);
        // 左子树深度等于右子树深度, 则左子树是满二叉树
        if(left_levels == right_levels){
            return countNodes(root->right) + (1<<left_levels);
        }else{
            return countNodes(root->left) + (1<<right_levels);
        }
    }
};