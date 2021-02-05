
#include "../code328/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode* in = new ListNode(1, new ListNode(2));
    in->next->next = new ListNode(3);
    in->next->next->next = new ListNode(4);
    in->next->next->next->next = new ListNode(5);

    test->oddEvenList(in);

    return 0;
}