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
    vector<vector<int>> out;
    vector<int> cur;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        backtrack(root, sum);
        return out;
    }

    void backtrack(TreeNode* root, int sum){
        if (root==nullptr)
            return;
        
        sum = sum - root->val;
        cur.push_back(root->val);
        if ((0 == sum) && (root->left==nullptr) && (root->right == nullptr))
            out.push_back(cur);
        backtrack(root->left,sum);
        backtrack(root->right,sum);
        cur.pop_back();
    }
};