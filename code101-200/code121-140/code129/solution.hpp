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
public:
    int m_sum = 0;
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == nullptr)
            return 0;
        calcSum(root, sum);
        return m_sum;
    }
    void calcSum(TreeNode* root , int &sum){
        int right_value = 0;
        int left_value = 0;
        if (root == nullptr)
            return;
        else if (root->left || root->right)
        {
            left_value = sum*10 + root->val;
            right_value = left_value;
            calcSum(root->left, left_value);
            calcSum(root->right, right_value);
        }
        else{
            m_sum += (sum*10 + root->val);
        }
    }
};