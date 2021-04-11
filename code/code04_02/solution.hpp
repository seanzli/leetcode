#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right)   
            return nullptr;
        if (left == right)  
            return new TreeNode(nums[left]);
        if (right - left == 1) {
            TreeNode* left_node  = new TreeNode(nums[left]);
            TreeNode* right_node = new TreeNode(nums[right]);
            left_node->right = right_node;
            return left_node;
        }
        int mid = left + (right - left) / 2;
        TreeNode* mid_node = new TreeNode(nums[mid]);
        mid_node->left = sortedArrayToBST(nums, left, mid - 1);
        mid_node->right = sortedArrayToBST(nums, mid + 1, right);
        
        return mid_node;
    }
};