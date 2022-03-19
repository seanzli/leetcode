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
    string res = "";
public:
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        res += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
            return;
        res += "(";
        dfs(root->left);
        res += ")";
        if (root->right) {
            res += "(";
            dfs(root->right);
            res += ")";
        }
        return;
    }
};