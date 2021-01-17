#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    vector<Node*> backup_node;
    unordered_map<int, int> hash;

    Node* cloneGraph(Node* node) {
        if (node== nullptr)
            return nullptr;
        recursion(node);
        rebuildGraph(node, backup_node[0]);
        return backup_node[0];
    }
    void recursion(Node* node){
        if (node==nullptr)
            return;

        if (hash.find(node->val)==hash.end())
        {
            hash[node->val] = backup_node.size();
            backup_node.push_back(new Node(node->val));
        }
        else
        {
            return;
        }

        for (int i = 0; i<node->neighbors.size(); i++)
            recursion(node->neighbors[i]);
    }
    void rebuildGraph(Node* node, Node* out){
        if (out->neighbors.size()>0)
            return;
        for (int i = 0; i<node->neighbors.size(); i++)
        {
            out->neighbors.push_back(backup_node[hash[node->neighbors[i]->val]]);
            rebuildGraph(node->neighbors[i], out->neighbors[i]);
        }
    }
};