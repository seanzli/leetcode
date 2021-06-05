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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        if (p->val > q->val)
            swap(q, p);
        return lowestCommonAncestor(root, p->val, q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, const int& p, const int& q) {
        if (root->val >= p && root->val <= q)
            return root;
        else if (root->val < p)
            return lowestCommonAncestor(root->right, p, q);
        else if (root->val > q)
            return lowestCommonAncestor(root->left, p, q);
    }
};