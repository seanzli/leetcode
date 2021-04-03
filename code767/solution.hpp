#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> hash;
        for (char cur : S)
            hash[cur]++;
        priority_queue<pair<int, char>> que;
        for (auto itr = hash.begin(); itr != hash.end(); itr++)
            que.push(make_pair(itr->second, itr->first));
        string res = "";
        while (que.size()) {
            auto itr_1 = que.top(); que.pop();
            if (res.size() > 0 && res.back() == itr_1.second) {
                if (que.size() > 0) {
                    auto itr_2 = que.top(); que.pop();
                    res += itr_2.second;
                    itr_2.first--;
                    if (itr_2.first > 0)
                        que.push(itr_2);
                    que.push(itr_1);
                } else {
                    return "";
                }
            } else {
                itr_1.first--;
                res += itr_1.second;
                if (itr_1.first > 0)
                    que.push(itr_1);
            }
        }
        return res;
    }
};