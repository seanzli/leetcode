#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (string str : words)
            hash[str]++;
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {return a.second == b.second ? a.first < b.first : a.second > b.second;};
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            que.push(*itr);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> res;
        while (que.size()) {
            res.push_back(que.top().first);
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};