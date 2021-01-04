
#include "../code24/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(9))));
    ListNode *l2 = new ListNode(-1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));//, new ListNode(4)));
    vector<ListNode*> lists = {l1,nullptr,l2};
    ListNode *out= test->swapPairs(l2);

    return 0;
}