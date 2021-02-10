#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int a, int b){return abs(a-x) < abs(b-x);});
        vector<int> out;
        for (int i=0; i<k; i++)
            out.push_back(arr[i]);
        sort(out.begin(), out.end());
        return out;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto res = arr;
        while (res.size() > k) {
            if (x - res.front() > res.back() - x) {
                res.erase(res.begin());
            } else {
               res.pop_back();
            }
        }

        return res;
    }
};