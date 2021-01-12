#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre=nullptr, *left, *right, *next = nullptr, *dummy = new ListNode(0);
        dummy->next = head;
        left = head;
        if (m==n)
            return head;
        
        for (int i = 1; i < m; i++)
        {
            pre = left;
            left = left->next;
        }
        right = left->next;
        for (int i = m; i < n; i++)
        {
            next = right->next;// next = 4
            right->next = left;// 3->2
            left = right; // left = 3
            right = next; //right = 4
        }

        if (pre)
        {
            pre->next->next = next;
            pre->next = left;
        }
        else
        {
            dummy->next->next = next;
            dummy->next = left;
        }
        return dummy->next;
    }
};