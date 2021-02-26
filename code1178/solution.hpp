#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Tril {
    int count = 0;
    vector<Tril*> child;
    Tril() : count(0), child(vector<Tril*>(26, nullptr)) {};
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // word tril
        Tril* root = new Tril();

        // add to tril
        for (string word : words) {
            Tril* cur = root;
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            for (char i : word) {
                if (cur->child[i - 'a'] == nullptr)
                    cur->child[i - 'a'] = new Tril();
                cur = cur->child[i - 'a'];
            }
            cur->count++;
        }

        // find puzzles
        vector<int> res;
        for (string str : puzzles) {
            queue<Tril*> que;
            int count = 0;
            char head_char = str[0];
            sort(str.begin(), str.end());
            res.push_back(find(str, head_char, root, 0));
        }
        return res;
    }

    int find(const string& puzzle, char required, Tril* cur, int pos) {
        if (cur == nullptr) 
            return 0;

        if (pos == puzzle.size())
            return cur->count;
        
        int ret = find(puzzle, required, cur->child[puzzle[pos] - 'a'], pos + 1);

        if (puzzle[pos] != required) {
            ret += find(puzzle, required, cur, pos + 1);
        }
        
        return ret;
    };
};