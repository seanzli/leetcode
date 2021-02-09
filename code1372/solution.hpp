#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int max_length = 0;
public:
    int longestZigZag(TreeNode* root) {
        order(root);
        return max_length-1;
    }

    void order(TreeNode* root){
        if (root==nullptr)  return;
        int zig = max(getZig(root,0), getZig(root,1));
        max_length = max(max_length, zig);
        order(root->left);
        order(root->right);
        return;
    }

    int getZig(TreeNode* root, int dir){
        if (root==nullptr)  return 0;
        
        int cur = 0;
        if (dir==0)
            cur = getZig(root->left, 1-dir);
        else
            cur = getZig(root->right, 1-dir);
        return cur+1;
    }
};

class Solution {
public:
    int maxAns;

    /* 0 => left, 1 => right */
    void dfs(TreeNode* o, bool dir, int len) {
        maxAns = max(maxAns, len);
        if (!dir) {
            if (o->left) dfs(o->left, 1, len + 1);
            if (o->right) dfs(o->right, 0, 1);
        } else {
            if (o->right) dfs(o->right, 0, len + 1);
            if (o->left) dfs(o->left, 1, 1);
        }
    } 

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        maxAns = 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return maxAns;
    }
};