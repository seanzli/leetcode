
#include "../code23/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<ListNode*> lists;
    lists.push_back(nullptr);
/*    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
     lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6))); */

    ListNode *out = test->mergeKLists(lists);

    return 0;
}