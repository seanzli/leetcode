#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    static bool func(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i : nums)
            hash[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&func)> que(func);
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            que.push(make_pair(itr->second, itr->first));
            if (que.size() > k)
                que.pop();
        }
        vector<int> res;
        while (que.size()) {
            res.push_back(que.top().second);
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
}; */