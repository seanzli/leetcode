
#include "../code1-100/code81-100/code94/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* in = new TreeNode(1);
    in->right = new TreeNode(2);
    in->right->left = new TreeNode(3);
    test->inorderTraversal(in);
    return 0;
}