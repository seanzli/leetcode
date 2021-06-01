#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int res;
public:
    int kthLargest(TreeNode* root, int& k) {
        if (k == 0)
            return res;
        if (root == nullptr)
            return res;
        kthLargest(root->right, k);
        if (k == 0)
            return res;
        if (--k == 0) {
            res = root->val;
            return res;
        }
        kthLargest(root->left, k);
        return res;
    }
};