#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int, greater<char>> hash;
        vector<pair<char, int>> vec;
        for (char i : tasks)
            hash[i]++;
        int sum_time = 0;
        int task_num = tasks.size();

        for (auto itr = hash.begin(); itr!= hash.end(); itr++)
            vec.push_back(make_pair(itr->first, itr->second));
        
        sort(vec.begin(), vec.end(), [](pair<char, int> a, pair<char, int> b){return a.second > b.second;});

        while (vec.size()) {
            int count = n + 1;
            sort(vec.begin(), vec.end(), [](pair<char, int> a, pair<char, int> b){return a.second > b.second;});
            for (auto itr = vec.begin(); itr!= vec.end(); ) {
                itr->second--;
                count--;
                task_num--;
                if (itr->second == 0)
                    itr = vec.erase(itr);
                else
                    itr++;
                if (count == 0)
                    break;
            }
            if (task_num == 0)
                sum_time += (n + 1 - count);
            else
                sum_time += (n + 1);
        }
        return sum_time;
    }
};

/* class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }
        
        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto [_, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j) {
                if (rest[j]) {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }

        return time;
    }
}; */