#include <iostream>
#include <string>
#include <vector>

using namespace std;

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *out = nullptr, *head;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        if (l1->val < l2->val)
        {
            out = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            out = new ListNode(l2->val);
            l2 = l2->next;
        }
        head = out;
        
        while (l1!=nullptr && l2!=nullptr)
        {
            if (l1->val < l2->val)
            {
                out->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                out->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            out = out->next;
        }
        if (l1)
            out->next = l1;
        else
            out->next = l2;
        return head;
    }
};