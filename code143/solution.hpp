#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    void reorderList(ListNode* head) {
        ListNode *tail = head, *cur = head, *mid = nullptr;
        vector<ListNode*> node_list;
        if (head == nullptr)
            return;
        while (tail)
        {
            node_list.push_back(tail);
            tail = tail->next;
        }
        
        int idx_start = 0, idx_end = node_list.size()-1;
        while (idx_start < idx_end){
            node_list[idx_start]->next = node_list[idx_end];
            node_list[idx_end]->next = node_list[idx_start+1];
            idx_start++;
            idx_end--;
        }
        node_list[idx_start]->next = nullptr;
    }
};