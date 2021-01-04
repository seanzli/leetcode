
#include "../code21/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode *L1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *L2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *L3 = nullptr;
    ListNode *L4 = nullptr; 
    ListNode *out = test->mergeTwoLists(L1, L4) ;

    return 0;
}