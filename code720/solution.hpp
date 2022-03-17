#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//    struct Tire {
//        bool isEnd;
//        vector<Tire*> child;
//        Tire() {
//            isEnd = false;
//            child = vector<Tire*>(26, nullptr);
//        };
//    };
//public:
//    string longestWord(vector<string>& words) {
//        Tire* root = new Tire();
//        for (string str : words) {
//            Tire* cur = root;
//            for (char i : str) {
//                if (cur->child[i - 'a'] == nullptr)
//                    cur->child[i - 'a'] = new Tire();
//                cur = cur->child[i - 'a'];
//            }
//            cur->isEnd = true;
//        }
//
//        string res = "";
//        string cur = "";
//        dfs(root, res, cur);
//        return res;
//    }
//
//    void dfs(Tire* root, string& res, string& cur) {
//        for (int i = 0; i < 26; ++i) {
//            if (root->child[i] == nullptr)
//                continue;
//            if (root->child[i]->isEnd == true) {
//                cur += (i + 'a');
//                dfs(root->child[i], res, cur);
//                if (res.size() < cur.size()) {
//                    res = cur;
//                }
//                cur.pop_back();
//            }
//        }
//    }
//};

class Trie {
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }

    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};