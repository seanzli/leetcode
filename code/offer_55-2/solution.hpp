#include <vector>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int depth = 0;
        return dfs(root, depth);
    }
    bool dfs(TreeNode* root, int& depth) {
        if (root == nullptr)
            return true;
        int left = 0, right = 0;
        if (dfs(root->left, left) && dfs(root->right, right) && abs(left - right) < 2) {
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
};