

#include "../code2/solution.hpp"

int main(){
    Solution *p = new Solution();
    ListNode L1(9, new ListNode(9));
    ListNode L2(9, new ListNode(9, new ListNode(9)));
    p->addTwoNumbers(&L1, &L2);
    return 0;
}