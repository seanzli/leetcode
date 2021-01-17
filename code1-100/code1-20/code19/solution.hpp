#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <math.h>

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
    /* ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *c=head->next,*r;
        if (head->next!=nullptr)
            r = head->next->next;
        else
            return nullptr;

        l->next = nullptr;
        while(1){
            c->next = l; //reverse
            l = c; //move
            c = r;
            if (r)
                r = r->next;
            else
                break;
        }
        
        head = l;l=head;r=head->next;
        if (n==1)
            head = head->next;
        else
        {
            for (int i = 1; i < n-1; i++)
            {
                l = l->next;
                r = r->next;
            }
            l->next = r->next;
        }

        l = head, c=head->next;
        if(head->next)
        {
            r = head->next->next;
            l->next = nullptr;
            while(1){
                c->next = l; //reverse
                l = c; //move
                c = r;
                if (r)
                    r = r->next;
                else
                    break;
            }
            return l;
        }
        else
        {
            return l;
        }
    } */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1=head, *p2=head;

        for (int i = 0; i < n; i++)
            p1 = p1->next;
        if (!p1)
            return head->next;

        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};