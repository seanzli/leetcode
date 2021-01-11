#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
/*     ListNode* deleteDuplicates(ListNode* head) {
        ListNode *left, *mid, *right;

        int cur = INT_MIN;
        while (1) // cur duplicate front;
        {
            left = head;
            if (!head)
                return head;
            if (left->val == cur)
            {
                head = head->next;
                continue;
            }
            mid = head->next;
            if (!mid)
                return head;
            right = mid->next;

            if (left->val == mid->val)
            {
                cur = left->val;
                head = mid->next;
            }
            else
                break;
        }
        
        bool flag = false;
        while (1){
            if (right)
            {
                if (right->val == mid->val) // find duplicate
                {
                    flag = true;
                    mid = mid->next;
                    right = right->next;
                }
                else{
                    if (flag) // cut
                    {
                        left->next = right;
                        mid = mid->next;
                        right = right->next;
                        flag = false;
                    }
                    else
                    {
                        left = left->next;
                        mid = mid->next;
                        right = right->next;
                    }
                }
            }
            else{
                if (flag)
                    left->next = nullptr;
                return head;
            }
        }
        return head;
    } */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *pre = dummy, *left=head, *right=head, *del;
        while (pre->next)
        {
            left  = pre->next;
            right = pre->next;
            while ((right->next != nullptr) && (left->val == right->next->val))
                right = right->next;
            if (right == left)
            {
                pre = pre->next;
            }
            else
            {
                pre->next = right->next;
                while (left != right){
                    del = left;
                    left = left->next;
                    delete del;
                }
            }
        }
        del = dummy;
        dummy = dummy->next;
        delete del;
        return dummy;
    }
};