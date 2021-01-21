#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *idx1 = headA, *idx2 = headB;
        
        while (idx1 != idx2){
            if (idx1)
                idx1 = idx1->next;
            else
                idx1 = headB;
            
            if (idx2)
                idx2 = idx2->next;
            else
                idx2 = headA;
        }
        return idx1;
    }
};