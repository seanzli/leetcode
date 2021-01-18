
#include "../code143/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode*in = new ListNode(3);
    in->next = new ListNode(2);
    in->next->next = new ListNode(0);
    in->next->next->next = new ListNode(-4);
    in->next->next->next->next = new ListNode(5);

    test->reorderList(in);

    while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl;
    return 0;
}