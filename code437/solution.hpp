#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

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
    vector<int> m_vec;
    int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        order(root, sum);
        return count;
    }
    void order(TreeNode *root, int sum){
        if (root == nullptr)    return;
        m_vec.push_back(root->val);
        int cur = 0;
        for (int i = m_vec.size()-1; i >=0; i--){
            cur += m_vec[i];
            if (cur == sum)
                count++;
        }
        order(root->left, sum);
        order(root->right, sum);
        m_vec.pop_back();
    }
};