
#include "../code1373/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    TreeNode* in = new TreeNode(3);
    in->left = new TreeNode(4);
    in->left->left = new TreeNode(2);
    in->left->right = new TreeNode(4);
    in->right = new TreeNode(3);
    in->right->left = new TreeNode(2);
    in->right->right = new TreeNode(5);
    in->right->right->left = new TreeNode(4);
    in->right->right->right = new TreeNode(6);

    test->maxSumBST(in);
    return 0;
}