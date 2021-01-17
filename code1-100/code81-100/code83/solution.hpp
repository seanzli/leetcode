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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *left = head, *del;
        while (left && left->next)
        {
            if (left->val == left->next->val)
            {
                del = left->next;
                left->next = left->next->next;
                delete del;
            }
            else
                left = left->next;
        }
        return head;
    }
};