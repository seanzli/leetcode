#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == nullptr)
            return depth;
        queue<TreeNode*> que;
        que.push(root);
        while (que.size()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = que.front(); que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
}; */

class Solution {
    int depth = 0;
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return depth;
    }
    void dfs(TreeNode* root, int cur) {
        if (root == nullptr) {
            depth = max(depth, cur);
            return;
        }
        
        dfs(root->left, cur + 1);
        dfs(root->right, cur + 1);
    }
};