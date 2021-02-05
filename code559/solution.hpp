#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

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
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        queue<Node*> m_queue;
        m_queue.push(root);
        int max_depth = 0;
        while (m_queue.size()){
            int n = m_queue.size();
            for (int i=0; i<n; i++){
                Node* cur = m_queue.front();
                m_queue.pop();
                for (int j = 0; j < cur->children.size(); j++)
                    m_queue.push(cur->children[j]);
            }
            max_depth++;
        }
        return max_depth;
    }
};