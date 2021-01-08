#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <list>
#include <algorithm>

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0 ;
        ListNode *sub = head, *end_p;

        if (head==nullptr)
            return head;
        
        while (sub!=nullptr)
        {
            n++;
            end_p = sub;
            sub = sub->next;
        }
        
        k = n-k%n;
        if (k==n)
            return head;
        
        sub = head->next;
        ListNode *mid = head;
        for (int i = 0; i < k-1; i++)
        {
            sub = sub->next;
            mid = mid->next;
        }
        mid->next = nullptr;
        end_p->next = head;
        
        return sub;
    }
};