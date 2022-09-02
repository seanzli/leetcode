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
    int res = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr)
            return 0;
        longestUnivaluePath(root, INT_MAX);
        return res;
    }
    int longestUnivaluePath(TreeNode* root, int val) {
        if (root == nullptr)
            return 0;

        int left = longestUnivaluePath(root->left, root->val);
        int right = longestUnivaluePath(root->right, root->val);
        res = max(res, left + right);

        return root->val == val ? max(left, right) + 1 : 0;
    }
};