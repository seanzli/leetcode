
#include "../code652/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* in = new TreeNode(2);
    in->left = new TreeNode(1);
    in->right = new TreeNode(11);
    in->left->left = new TreeNode(11);
    in->right->left = new TreeNode(1);
    test->findDuplicateSubtrees(in);

    return 0;
}