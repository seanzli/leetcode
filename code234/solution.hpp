#include <cstdio>
#include <iostream>
#include <vector>

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
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head, *slow=head;
        vector<int> value;
        if ((head==nullptr)||(head->next==nullptr)) return true;
        while((fast!=nullptr)&&(fast->next!=nullptr)){
            fast = fast->next->next;
            value.push_back(slow->val);
            slow = slow->next;
        }
        int idx = value.size()-1;
        if (fast!=nullptr)
            slow = slow->next;
        while (idx>=0){
            if (slow->val != value[idx])
                return false;
            idx--;
            slow = slow->next;
        }
        return true;
    }
};