#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>
#include <queue>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur){
            if (cur->val == val)
            {
                pre->next = cur->next;
                ListNode *del = cur;
                cur = cur->next;
                delete del;
            }
            else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};