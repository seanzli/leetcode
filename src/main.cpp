#include "../code863/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    test->distanceK(root, root->left, 2);

    return 0;
}

// int main(int argc, char* argv[]) {
//     Codec temp;
//     TreeNode *node = new TreeNode(1);
//     node->left = new TreeNode(2);
//     node->right = new TreeNode(3);
//     node->right->left = new TreeNode(4);
//     node->right->right = new TreeNode(5);

//     cout << temp.serialize(node) << endl;
//     TreeNode* cur = temp.deserialize(temp.serialize(nullptr));

//     return 0;
// }
