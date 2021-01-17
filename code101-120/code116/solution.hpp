#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        queue<Node*> backup_list;
        backup_list.push(root);
        Node *cur = nullptr;

        while (backup_list.size()){
            int n = backup_list.size();
            cur = backup_list.front();
            backup_list.pop();
            if (cur->left)
            {
                backup_list.push(cur->left);
                backup_list.push(cur->right);
            }
            for (int i=1; i<n; i++)
            {
                cur->next = backup_list.front();
                cur = backup_list.front();
                if (cur->left)
                {
                    backup_list.push(cur->left);
                    backup_list.push(cur->right);
                }
                backup_list.pop();
            }
            cur->next = nullptr;
        }
        return root;
    }
};