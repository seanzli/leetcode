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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
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
    }
};