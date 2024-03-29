#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)    return nullptr;
        Node* out = nullptr;
        Node* move_head = head;
        unordered_map<Node*,Node*> map;

        map[nullptr] = nullptr;
        while (move_head)
        {
            map[move_head] = new Node(move_head->val);
            move_head = move_head->next;
        }
        out = map[head];
        Node* move_out = out;
        move_head = head;
        while (move_head){
            move_out->next = map[move_head->next];
            move_out->random = map[move_head->random];
            move_head = move_head->next;
            move_out = move_out->next;
        }
        return out;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
};