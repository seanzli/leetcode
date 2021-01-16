
#include "../code108/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    ListNode *in = new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9)))));
    TreeNode* out =  test->sortedListToBST(in);

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