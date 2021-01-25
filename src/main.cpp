
#include "../code222/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << test->countNodes(root) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}