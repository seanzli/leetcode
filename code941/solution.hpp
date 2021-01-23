#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 1;
        for (; i < n; i++)
        {
            if (arr[i] == arr[i-1])
                return false;
            if (arr[i] < arr[i-1])
                break;
        }
        if ((i == 1) || (i==n))  return false;
        for (; i< n; i++){
            if (arr[i] >= arr[i-1])
                return false;
        }
        return true;
    }
};