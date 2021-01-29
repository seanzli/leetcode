
#include "../code701/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* in = new TreeNode(4);
    in->left = new TreeNode(2);
    in->right = new TreeNode(7);
    in->left->right = new TreeNode(3);
    in->left->left = new TreeNode(1);

    test->insertIntoBST(in,5);


    return 0;
}