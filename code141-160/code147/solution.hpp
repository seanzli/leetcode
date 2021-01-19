#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head->next;
        ListNode *lastSord = head;
        while(cur)
        {
            if (lastSord->val<=cur->val){
                lastSord = lastSord->next;
            }
            else{
                ListNode *pre = dummy;
                while (pre->next->val <= cur->val)
                    pre = pre->next;
                lastSord->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = lastSord->next;
        }
        return dummy->next;
    }
};