/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-07-31 15:26:01
 * @LastEditTime: 2021-07-31 15:53:09
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct T {
    int row, col, val;
    T(int _row, int _col, int _val) : row(_row), col(_col), val(_val) {}
};

bool operator<(const T& b, const T& a) {
    if (a.col < b.col) 
        return true;
    if (a.col > b.col)
        return false;
    if (a.row < b.row)
        return true;
    if (a.row > b.row)
        return false;
    if (a.val < b.val)
        return true;
    if (a.val > b.val)
        return false;
    return true;
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        priority_queue<T> que;
        dfs(root, que, 0, 0);
        if (que.size() == 0)
            return res;
        int col = que.top().col; // cur col;
        vector<int> cur;
        while (que.size()) {
            auto t = que.top(); que.pop();
            if (cur.size() == 0 || col == t.col) {
                cur.push_back(t.val);
            } else {
                res.push_back(cur);
                cur.clear();
                cur.push_back(t.val);
                col = t.col;
            }
        }
        if (cur.size())
            res.push_back(cur);
        return res;
    }
    void dfs(TreeNode* node, priority_queue<T>& que, const int row, const int col) {
        if (node == nullptr)
            return;
        que.push(T(row, col, node->val));
        dfs(node->left, que, row + 1, col - 1);
        dfs(node->right, que, row + 1, col + 1);
        return;
    }
};