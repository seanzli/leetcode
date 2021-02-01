#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> out;
        sort(arr.begin(), arr.end());
        for (int i = 0; i<k;i++)
            out.push_back(arr[i]);
        return out;
    }
};