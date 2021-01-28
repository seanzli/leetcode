#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    int minval = INT_MAX;
    TreeNode* prev = nullptr;
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minval;
    }
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root -> left);
        if(prev) minval = min(minval, root -> val - prev -> val);
        prev = root;
        inorder(root -> right);
    }
};