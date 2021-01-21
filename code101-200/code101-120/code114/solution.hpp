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
    
/*     TreeNode *out = new TreeNode(0);
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode *cur = out;
        inorder(root, cur);
        root = out->right;
        return;
    }
    void inorder(TreeNode* root, TreeNode* cur){
        if (root == nullptr)
            return;
        
        while (cur->right)
            cur = cur->right;
        cur->right = new TreeNode(root->val);
        inorder(root->left, cur);
        inorder(root->right, cur);
    } */
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur){
            if (cur->left){
                TreeNode* next = cur->left;
                TreeNode* pred = next;
                while (pred->right)
                    pred = pred->right;
                pred->left = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};