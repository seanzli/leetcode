
#include "../code234/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    ListNode *in = new ListNode(1);
    in->next = new ListNode(2);
    in->next->next = new ListNode(2);
    in->next->next->next = new ListNode(4);
    cout << test->isPalindrome(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}