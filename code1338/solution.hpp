#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> hash; // num - count idx
        vector<int> count; // count - num
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (hash.find(arr[i]) == hash.end()) {
                hash[arr[i]] = count.size();
                count.push_back(1);
            } else {
                count[hash[arr[i]]]++;
            }
        }
        sort(count.begin(), count.end(), greater<int>());
        int del_num = 0;
        int idx = 0;
        for (idx = 0; idx < count.size(); idx++) {
            del_num += count[idx];
            if (del_num >= n / 2)
                break;
        }
        return idx;
    }
};