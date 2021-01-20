#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    vector<int> value_list;
    int cur_idx = 0;
public:
    BSTIterator(TreeNode* root) {
        preoreder(root);
    }
    
    int next() {
        return value_list[cur_idx++];
    }
    
    bool hasNext() {
        return (cur_idx < value_list.size());
    }

    void preoreder(TreeNode *root){
        if (root == nullptr)
            return;
        
        preoreder(root->left);
        value_list.push_back(root->val);
        preoreder(root->right);
    }
};