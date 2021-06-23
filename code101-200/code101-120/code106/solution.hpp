#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> hash; // postorder value -> inorder idx
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = 0;
        for (int& val : inorder)
            hash[val] = idx++;
        idx = 0;
        return buildTree(inorder, postorder, 0, inorder.size(), idx);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int i_left, int i_right, int& root_idx) {
        if (i_left > i_right)
            return nullptr;
        if (i_left == i_right)
            return new TreeNode(inorder[i_left]);
        
        TreeNode* root = new TreeNode(postorder[root_idx]);
        int idx = hash[postorder[root_idx]];
        root_idx--;
        root->right = buildTree(inorder, postorder, idx + 1, i_right, root_idx);
        root->left = buildTree(inorder, postorder, i_left, idx - 1, root_idx);
        return root;
    }
};