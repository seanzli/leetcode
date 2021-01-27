
#include "../code257/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode*in = new TreeNode(1);
    in->left = new TreeNode(2);
    in->right = new TreeNode(3);
    in->left->right = new TreeNode(5);
    vector<string> out = test->binaryTreePaths(in);

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}