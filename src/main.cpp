
#include "../code1325/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* in = new TreeNode(1);
    in->left = new TreeNode(2);
    in->left->left = new TreeNode(2);
    in->right = new TreeNode(3);
    in->right->left = new TreeNode(2);
    in->right->right = new TreeNode(4);
    test->removeLeafNodes(in, 2);
    return 0;
}