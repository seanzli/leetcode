#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        getNumsList(root, nums);
        pair<int,int> error_num = findTwoSwapped(nums);
        recover(root, 2, error_num.first, error_num.second);
    }
    void getNumsList(TreeNode* root, vector<int> &nums){
        if (root)
        {
            getNumsList(root->left, nums);
            nums.push_back(root->val);
            getNumsList(root->right, nums);
        }
        return;
    }
    pair<int,int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                }
                else break;
            }
        }
        return {x, y};
    }
    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }
};