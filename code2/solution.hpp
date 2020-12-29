
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0, cur_num = 0;
        ListNode *p_out = new ListNode();
        ListNode *p = p_out;

        while (l1 !=nullptr | l2 !=nullptr)
        {
            cur_num = l1->val + l2->val + temp;
            if (cur_num > 9)
            {
                p_out->val = cur_num - 10;
                temp = 1;
            }
            else
            {
                p_out->val = cur_num;
                temp = 0;
            }


            if(l1->next !=nullptr | l2->next !=nullptr)
            {
                p_out->next = new ListNode(temp);
                p_out = p_out->next;
            }
            else{
                if (temp)                
                    p_out->next = new ListNode(temp);
                break;
            }
            if(l1->next == nullptr)
                l1->next = new ListNode(0);
            if(l2->next == nullptr)
                l2->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }

        return p;
    }
};