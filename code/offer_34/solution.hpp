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
private:
    vector<int> cur;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target, 0);
        return res;
    }
    void dfs(TreeNode* root, const int & target, int sum) {
        if (root == nullptr)
            return;
        cur.push_back(root->val);
        sum += root->val;
        if (sum == target && root->left == nullptr && root->right == nullptr)
            res.push_back(cur);
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        cur.pop_back();
        return;
    }
};