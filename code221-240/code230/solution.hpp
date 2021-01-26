#include <cstdio>
#include <iostream>
#include <vector>
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
private:
    int value = 0;
    int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        order(root);
        return value;
    }
    
    void order(TreeNode* root){
        if (root == nullptr)
            return;
        
        order(root->left);
        if (count == 0)
            return;
        value = root->val;
        count--;
        order(root->right);
        return;
    }
};