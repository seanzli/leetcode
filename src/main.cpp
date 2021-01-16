
#include "../code105/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *in = test->buildTree(preorder, inorder);

    

    return 0;
}