#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

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
    ListNode* swapPairs(ListNode* head) {
        int cur_val = 0;
        if (head==nullptr)
            return nullptr;
        ListNode *cur = head;
        ListNode *last = head;
        if (cur->next)
            cur = cur->next;
        
        while (cur)
        {
            cur_val = last->val;
            last->val = cur->val;
            cur->val = cur_val;
            if (cur->next)
                last = cur->next;
            else
                break;
            
            if (last->next)
                cur = last->next;
            else
                break;
        }
        return head;
    }
};