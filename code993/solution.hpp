#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    vector<int> dfs(TreeNode* root, TreeNode* fa, int depth, int t){
        if(root ==nullptr)  return vector<int>{-1, -1};
        if(root->val == t){
            return vector<int>{fa != nullptr ? fa->val : 1, depth};
        }
        vector<int> l = dfs(root->left, root, depth + 1, t);
        if(l[0] != -1)  return l;
        return dfs(root->right, root, depth + 1, t);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> xi = dfs(root, nullptr, 0, x);
        vector<int> yi = dfs(root, nullptr, 0, y);
        return xi[1] == yi[1] && xi[0] != yi[0];
    }
};
