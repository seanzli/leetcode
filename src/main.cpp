
#include "../code1019/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode *in = new ListNode(2);
    in->next = new ListNode(1);
    in->next->next = new ListNode(5);

    vector<int> out = test->nextLargerNodes(in);
    return 0;
}