
#include "../code1372/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    TreeNode* in = new TreeNode(1);
    in->right = new TreeNode(1);
    in->right->left = new TreeNode(1);
    in->right->right = new TreeNode(1);
    in->right->right->left = new TreeNode(1);
    in->right->right->right = new TreeNode(1);
    in->right->right->left->right = new TreeNode(1);
    in->right->right->left->right->right = new TreeNode(1);
    test->longestZigZag(in);

    return 0;
}