#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* head = new TreeNode(-1);   // 为了返回单向链表的头节点而多设的一个节点
    TreeNode* perv = nullptr;               // 指向当前节点的前一个节点
public:
    TreeNode* convertBiNode(TreeNode* root) {
        order(root);
        return head->right;
    }

    void order(TreeNode* root) {
            if (root == nullptr) { return;}
            order(root->left);
            if (perv == nullptr) {     // 第一个节点
                perv = root;        // 记录第一个节点
                head->right = root;  // 记录它，它将作为单链表的表头
            } else {                // 第一个节点之后的节点
                perv->right = root;  // 前一个节点的右指针指向当前节点
                perv = root;        // 更新perv指向
            }
            root->left = nullptr;       // 当前节点的左指针设为null
            order(root->right);
    }
};