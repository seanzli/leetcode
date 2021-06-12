#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *idx1 = headA, *idx2 = headB;
        while (idx1 != idx2) {
            idx1 = idx1 == nullptr ? headB : idx1->next;
            idx2 = idx2 == nullptr ? headA : idx2->next; 
        }
        return idx1;
    }
};