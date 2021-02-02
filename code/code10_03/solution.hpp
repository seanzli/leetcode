#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        auto itr = find(arr.begin(), arr.end(), target);
        int dis = distance(arr.begin(), itr);
        if (dis == arr.size())
            return -1;
        return dis;
    }
};