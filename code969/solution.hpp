#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> out;
        int n = arr.size();
        for (int i = n-1; i >=0; i--)
        {
            auto itr = max_element(arr.begin(), arr.begin()+i+1);
            int idx = distance(arr.begin(), itr);
            if (idx == i)
                continue;
            reverse(arr.begin(), arr.begin()+idx+1);
            reverse(arr.begin(), arr.begin()+i+1);
            out.push_back(idx+1);
            out.push_back(i+1);
        }
        return out;
    }
};