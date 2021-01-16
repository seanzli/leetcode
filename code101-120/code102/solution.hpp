#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    vector<TreeNode*> list;
    vector<vector<int>> out;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return out;
        list.push_back(root);
        getListValue();
        return out;
    }
    void getListValue(){
        vector<int> cur;
        vector<TreeNode* >cur_list;
        if (list.size()<1)
            return;
        
        for (int i = 0; i < list.size(); i++)
        {
            cur.push_back(list[i]->val);
            if (list[i]->left)
                cur_list.push_back(list[i]->left);
            if (list[i]->right)
                cur_list.push_back(list[i]->right);
        }
        out.push_back(cur);
        list = cur_list;
        getListValue();
    }
};