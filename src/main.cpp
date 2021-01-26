
#include "../code236/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode *in = new TreeNode(3);
    in->left = new TreeNode(5);
    in->left->left = new TreeNode(6);
    in->left->right = new TreeNode(2);
    in->left->right->left = new TreeNode(7);
    in->left->right->right = new TreeNode(4);
    in->right = new TreeNode(1);
    in->right->left = new TreeNode(0);
    in->right->right = new TreeNode(8);

    cout << test->lowestCommonAncestor(in, in->left, in->left->right->right)->val << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}