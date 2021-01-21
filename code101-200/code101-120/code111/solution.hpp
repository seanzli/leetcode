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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int count = 1;
        queue<TreeNode*> tree_list;
        tree_list.push(root);
        while (tree_list.size()){
            int loop_size = tree_list.size();
            for (int i = 0 ;i<loop_size;i++)
            {
                TreeNode *cur = tree_list.front(); tree_list.pop();
                if ((cur->right == nullptr) && (cur->left == nullptr))
                    return count;
                
                if (cur->left)
                    tree_list.push(cur->left);
                if (cur->right)
                    tree_list.push(cur->right);
            }
            count++;
        }
        return count;
    }
};