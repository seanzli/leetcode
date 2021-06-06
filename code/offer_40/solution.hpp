#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

/* class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> out;
        sort(arr.begin(), arr.end());
        for (int i = 0; i<k;i++)
            out.push_back(arr[i]);
        return out;
    }
}; */

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i : arr) {
            que.push(i);
            if (que.size() > k)
                que.pop();
        }
        vector<int> res;
        while (que.size()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};