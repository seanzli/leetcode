#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


class NumArray {
private:

    struct TreeNode{
        TreeNode *p_left_node, *p_right_node;
        int sum, left, right;
        TreeNode(): p_left_node(nullptr), p_right_node(nullptr), sum(0), left(0), right(0){};
    };

    TreeNode *root = nullptr;
    TreeNode* buildTree(vector<int> &nums, int left, int right){
        TreeNode * node = new TreeNode();
        node->left = left;
        node->right = right;

        if (left > right){
            node->sum = 0;
            return node;
        }

        if (left == right){
            node->sum = nums[right];
            return node;
        }

        int mid = left + (right- left)/2;
        node->p_left_node = buildTree(nums, left, mid);
        node->p_right_node = buildTree(nums, mid+1, right);
        node->sum = node->p_left_node->sum + node->p_right_node->sum;
        return node;
    }

    void updataTreeNode(TreeNode*root, int idx, int val){
        if (root== nullptr)
            return;
        if (root->left == root->right && root->left == idx){
            root->sum = val;
            return;
        }
        int mid = root->left + (root->right - root->left)/2;
        if (idx <= mid){
            updataTreeNode(root->p_left_node, idx, val);
        }
        else{
            updataTreeNode(root->p_right_node, idx, val);
        }
        root->sum = root->p_left_node->sum + root->p_right_node->sum;
        return;
    }

    int query(TreeNode *root, int left, int right){
        if (root== nullptr)
            return 0;
        if (root->left == left && root->right == right)
            return root->sum;
        int mid = root->left + (root->right - root->left)/2;
        if (mid >= right)
            return query(root->p_left_node, left, right);
        else if (mid < left)
            return query(root->p_right_node, left, right);
        else{
            return query(root->p_left_node, left, mid) + 
                   query(root->p_right_node, mid+1, right);
        }
    }

public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        updataTreeNode(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(root, left, right);
    }
};
