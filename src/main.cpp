
#include "../code124/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode *in = new TreeNode(2);
    in->left = new TreeNode(-1);
/*     in->right = new TreeNode(20);
    in->right->left = new TreeNode(15);
    in->right->right = new TreeNode(7); */

    cout << test->maxPathSum(in) << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    return 0;
}