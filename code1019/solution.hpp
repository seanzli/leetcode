#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> temp;
        while(head != nullptr){
            temp.push_back(head->val);
            head=head->next;  
        }

        vector<int> res(temp.size(),0);
        for(int i = 0; i < temp.size(); i++){
            while(!st.empty() && temp[st.top()]<temp[i]){
                res[st.top()]=temp[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};