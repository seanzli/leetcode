#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> vec;  // value - label;
        unordered_map<int, int> hash; // label -> nums
        for (int i = 0; i < values.size(); i++) {
            vec.push_back(make_pair(values[i], labels[i]));
            hash[labels[i]]++;
            hash[labels[i]] = min(hash[labels[i]], use_limit);
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;});
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (hash[vec[i].second] > 0) {
                sum += vec[i].first;
                hash[vec[i].second]--;
                num_wanted--;
                if (num_wanted == 0)
                    return sum;
            }
        }
        return sum;
    }
};