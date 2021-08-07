#include "../code457/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    
    vector<int> nums = {-1, 2};

    test->circularArrayLoop(nums);

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
