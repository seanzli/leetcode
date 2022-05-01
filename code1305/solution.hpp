
#include <vector>
#include <numeric>
#include <algorithm>

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
    void dfs(TreeNode* root, vector<int>& out) {
        if (root == nullptr)
            return;
        dfs(root->left, out);
        out.push_back(root->val);
        dfs(root->right, out);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        dfs(root1, vec1);
        dfs(root2, vec2);
        vector<int> res;
        merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),  std::back_inserter(res));
        return res;
    }
};