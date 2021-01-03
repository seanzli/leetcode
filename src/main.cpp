
#include "../code19/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();


    ListNode *num_list = new ListNode(1, new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    //ListNode *num_list = new ListNode(1, new ListNode(2));
    //ListNode *num_list = new ListNode(1);
    int target = 2;
    test->removeNthFromEnd(num_list, target);

    return 0;
}