#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/* class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max_prod = 0;
        if (words.size() < 2)
            return max_prod;
        for (int i = 0; i < words.size() - 1; i++) {
            unordered_set<char> hash;
            for (char cur : words[i])
                hash.insert(cur);
            for(int j = i + 1; j < words.size(); j++) {
                int count = 1;
                for (char cur : words[j]) {
                    if (hash.count(cur) == 1) {
                        count = 0;
                        break;
                    }
                }
                count = count * words[i].size() * words[j].size();
                max_prod = max(max_prod, count);
            }
        }
        return max_prod;
    }
}; */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2)   return 0;
        vector<int> mark;
        for (string str : words) {
            int cur_mark = 0;
            for (char cur : str)
                cur_mark |= (1 << (cur - 'a'));
            mark.push_back(cur_mark);
        }
        int max_prod = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!(mark[i] & mark[j]))
                    max_prod = max(max_prod, (int)(words[i].size() * words[j].size()));
            }
        }
        return max_prod;
    }
};