#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1)
            return head;
        ListNode *void_head = new ListNode();
        void_head->next = head;
        ListNode *p_head = void_head, *p_tail = head;
        ListNode *p1=head, *p2=head->next, *p3=head->next;
        while (1)
        {
            for (int i = 0; i < k; i++)
            {
                if (p_tail)
                    p_tail = p_tail->next;
                else
                    return void_head->next;
            }
            p1 = p_head;
            p2 = p_head->next;
            p3 = p_head->next->next;
            while (1)
            {
                p2->next = p1;
                if (p3 == p_tail)
                    break;
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
            p_head->next->next = p3;
            p1 = p_head->next;
            p_head->next = p2;
            p_head = p1;
        }
        
    }
}; */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        stack<ListNode*> m_stack;
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0);
        ListNode* cur_head = dummy;
        while (cur) {
            m_stack.push(cur);
            if (m_stack.size() == k) {
                cur = cur->next;
                while (m_stack.size()) {
                    cur_head->next = m_stack.top();
                    m_stack.pop();
                    cur_head = cur_head->next;
                }
            } else {
                cur = cur->next;
            }
        }
        cur_head->next = nullptr;
        return dummy->next;
    }
};