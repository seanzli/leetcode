
#include "../code/code02_03/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode* in = new ListNode(1);
    in->next = new ListNode(2);
    in->next->next = new ListNode(3);
    test->deleteNode(in->next);
    return 0;
}