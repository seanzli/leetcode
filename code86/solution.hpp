#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode* preCur = nullptr;
        ListNode* cur = head;
        ListNode* preNext = nullptr;
        ListNode* next = head;
    
        while (next != nullptr) 
        {
            if (next->val >= x) 
            {
                preNext = next;
                next = next->next;
            } 
            else 
            {
                if (cur != next) 
                {
                    if (preCur == nullptr) 
                    {
                        head = next;
                    }
                    else
                    {
                        preCur->next = next;
                    }
                    preNext->next = next->next;
                    next->next = cur;
                    preCur = next;
                    next = preNext->next;
                } 
                else
                {
                    preCur = cur;
                    cur = cur->next;
                    preNext = next;
                    next = next->next;
                }
            }
        }
        return head;
    }
};