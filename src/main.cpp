#include "../code101-200/code161-180/code165/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    test->compareVersion("1.0", "1.0.0");

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
