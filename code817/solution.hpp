#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> hash;
        for (int i : G)
            hash.insert(i);
        int count = 0, max_count = 0;
        while (head != nullptr) {
            if (hash.count(head->val))
                count++;
            else {
                max_count = max(max_count, count);
                count = 0;
            }
            head = head->next;
        }
        max_count = max(max_count, count);
        return max_count;
    }
};