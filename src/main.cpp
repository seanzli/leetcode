
#include "../code141/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode*in = new ListNode(3);
    in->next = new ListNode(2);
    in->next->next = new ListNode(0);
    in->next->next->next = new ListNode(-4);
    in->next->next->next->next = in->next->next;

    cout << test->hasCycle(in) << endl;

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