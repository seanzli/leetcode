
#include "../code1-100/code21-40/code25/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode *in = new ListNode(2);
    in->next = new ListNode(1);
    in->next->next = new ListNode(5);

    test->reverseKGroup(in, 2);
    return 0;
}