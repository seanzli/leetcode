#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*> que;
        vector<ListNode*> res;
        if (tree == nullptr)
            return res;
        que.push(tree);
        while (que.size()) {
            int n = que.size();
            ListNode* dummy = new ListNode(0);
            ListNode* cur = dummy;
            for (int i = 0; i < n; i++) {
                TreeNode* cur_tree_node = que.front();
                que.pop();
                cur->next = new ListNode(cur_tree_node->val);
                cur = cur->next;
                if (cur_tree_node->left)
                    que.push(cur_tree_node->left);
                if (cur_tree_node->right)
                    que.push(cur_tree_node->right);
            }
            res.push_back(dummy->next);
            delete dummy;
        }
        return res;
    }
};