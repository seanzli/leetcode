
#include "../code129/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

/*     vector<int> nums1 = {1,2,3,4,5};
    ListNode *in = new ListNode(nums1[0]);
    ListNode *cur = nullptr;
    cur = in;
    for (int i = 1; i< nums1.size(); ++i)
    {
        cur->next = new ListNode(nums1[i]);
        cur = cur->next;
    } */
    //vector<vector<int>> in = {{2},{3,4},{6,5,7},{4,1,8,3}};
    //vector<int> in = {3,3,5,0,0,3,1,4};

    //vector<int> in = {1,2,0,1};
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << test->sumNumbers(root) << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    
/*     while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl; */

    return 0;
}