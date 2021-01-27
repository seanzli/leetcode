#include <cstdio>
#include <iostream>
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
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==nullptr) 
            return result;
        order(root, "");
        return result;
    }

    void order(TreeNode *root, string temp){
        if (temp.size()==0)
            temp = to_string(root->val);
        else
            temp += "->"+to_string(root->val);
        if ((root->left==nullptr) && (root->right==nullptr)){
            result.push_back(temp);
            return;
        }
        if (root->left)
            order(root->left, temp);
        if (root->right)
            order(root->right, temp);
    }
};