#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr || A == nullptr)
            return false;
        if (A->val == B->val && check(A, B))
            return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool check(TreeNode* A, TreeNode* B) {
        if (B == nullptr) 
            return true;
        if (A == nullptr)
            return false;
        
        if (A->val != B->val)
            return false;

        return check(A->left, B->left) && check(A->right, B->right);
    }

};