#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>
#include <queue>
#include <limits.h>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        if (root==nullptr)
            return out;
            
        queue<TreeNode*> list;
        list.push(root);
        while (list.size()){
            int n = list.size();
            int cur_value = INT_MIN;
            bool valid = false;
            for (int i = 0; i < n; i++)
            {
                TreeNode* cur = list.front();
                list.pop();
                if (cur){
                    valid = true;
                    cur_value = cur->val;
                    list.push(cur->left);
                    list.push(cur->right);
                }
            }
            if (valid)
                out.push_back(cur_value);
        }
        return out;
    }
};