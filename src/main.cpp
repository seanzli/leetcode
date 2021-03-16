
#include "../code971/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* in = new TreeNode(1);
    in->left = new TreeNode(2);
    in->right = new TreeNode(3);
    vector<int> v = {1,3,2};
    test->flipMatchVoyage(in, v);
    return 0;
}