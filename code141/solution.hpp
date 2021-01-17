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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        if (head == nullptr)
            return false;
        mp[head]++;
        while (head->next){
            if (mp.find(head->next) == mp.end())
                mp[head->next]++;
            else
                return true;
            head = head->next;
        }
        return false;
    }
};