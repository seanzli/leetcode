#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    struct pair_hash
    {
        template <class T1, class T2>
        size_t operator () (pair<T1, T2> const &pair) const
        {
            size_t h1 = hash<T1>()(pair.first); //用默认的 hash 处理 pair 中的第一个数据 X1
            size_t h2 = hash<T2>()(pair.second);//用默认的 hash 处理 pair 中的第二个数据 X2
            return h1 ^ h2;
        }
    };
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<pair<int, int>, pair_hash> hash;
        pair<int, int> pos = make_pair(0, 0);
        hash.insert(pos);
        for (char cur : command) {
            if (cur == 'U')
                pos.second++;
            else
                pos.first++;
            hash.insert(pos);
        }

        pair<int, int> cur = make_pair(x, y);
        int target_count = 1;
        target_count = min(cur.first / pos.first, cur.second / pos.second);
        cur.first = cur.first - pos.first * target_count;
        cur.second = cur.second - pos.second * target_count;
        if (hash.count(cur) == 0)
            return false;
        for (auto itr : obstacles) {
            if (x < itr[0] || y < itr[1])
                continue;
            int count = min(itr[0] / pos.first, itr[1] / pos.second);
            cur.first = itr[0] - pos.first * count;
            cur.second = itr[1] - pos.second * count;
            if (hash.count(cur) == 1)
                return false;
        }
        return true;
    }
};