
#include "../code221-240/code234/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode* in = new ListNode(1);
    in->next = new ListNode(2);
    in->next->next = new ListNode(1);
    in->next->next->next = new ListNode(2);
    in->next->next->next->next = new ListNode(1);
    test->isPalindrome(in);
    return 0;
}