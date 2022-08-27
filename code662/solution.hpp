#include <queue>

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> que;
        queue<unsigned int> idx;
        que.push(root);
        idx.push(0);
        unsigned res = 0;
        while (!que.empty()) {
            int n = que.size();
            unsigned int min_idx = idx.front(), max_idx = idx.front();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = que.front(); que.pop();
                auto cur_idx = idx.front(); idx.pop();
                min_idx = min(min_idx, cur_idx);
                max_idx = max(max_idx, cur_idx);
                if (cur->left) {
                    que.push(cur->left);
                    idx.push(cur_idx * 2);
                }
                if (cur->right) {
                    que.push(cur->right);
                    idx.push(cur_idx * 2 + 1);
                }
            }
            res = max(res, max_idx - min_idx + 1);
        }
        return res;
    }
};