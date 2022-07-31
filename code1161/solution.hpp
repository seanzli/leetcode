#include <queue>
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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr)
            return 0;
        que.push(root);
        int res = 0;
        int max_val = INT_MIN;
        int level = 0;
        while (!que.empty())
        {
            ++level;
            int size = que.size();
            int sum = 0;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->val;
                if (nullptr != cur->left)
                    que.push(cur->left);
                if (nullptr != cur->right)
                    que.push(cur->right);
            }
            if (max_val < sum)
            {
                max_val = sum;
                res = level;
            }
        }
        return res;
    }
};