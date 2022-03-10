
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void preorder(Node* root, vector<int>& res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        for (auto itr : root->children) {
            preorder(itr, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};