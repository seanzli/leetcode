
#include "../code817/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    vector<int> g = {0,1,3};
    test->numComponents(head, g);
    
    return 0;
}