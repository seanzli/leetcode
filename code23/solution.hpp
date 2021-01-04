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
/*     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size()<1)
            return nullptr;

        double min_value = 1e10;
        int min_idx = -1;
        ListNode *p_out = nullptr;
        ListNode *p_ = nullptr;
        while (1)
        {
            for (int i = 0; i < lists.size(); i++)
            {
                if ((lists[i]!=nullptr) && (lists[i]->val <= min_value))
                {
                    min_idx = i;
                    min_value = lists[i]->val;
                }
            }

            if (min_idx==-1)
                break;

            if (p_out == nullptr)
            {
                p_out = new ListNode(min_value);
                p_ = p_out;
            }
            else
            {
                p_out->next = new ListNode(min_value);
                p_out = p_out->next;
            }
            lists[min_idx] = lists[min_idx]->next;
            min_idx = -1;
            min_value = 1e10;
        }

        return p_;
    } */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)
            return nullptr;
        if (lists.size()==1)
            return lists[0];
        
        ListNode *p1 = lists[lists.size()-1], *p2=lists[lists.size()-2];
        ListNode *out, *cur;
        
        lists.pop_back();lists.pop_back();
        if (p1==nullptr)
        {
            lists.push_back(p2);
            return mergeKLists(lists);
        }
        if (p2==nullptr)
        {
            lists.push_back(p1);
            return mergeKLists(lists);
        }
        
        if (p1->val > p2->val)
        {
            out = new ListNode(p2->val);
            p2 = p2->next;
        }
        else
        {
            out = new ListNode(p1->val);
            p1 = p1->next;
        }
        cur = out;
        while ((p1!=nullptr) && (p2!=nullptr))
        {
            if (p1->val > p2->val)
            {
                cur->next = new ListNode(p2->val);
                cur = cur->next;
                p2 = p2->next;
            }
            else
            {
                cur->next = new ListNode(p1->val);
                cur = cur->next;
                p1 = p1->next;
            }
        }
        if (p1==nullptr)
            cur->next = p2;
        else if (p2==nullptr)
            cur->next = p1;
        lists.push_back(out);
        return mergeKLists(lists);
    }
};