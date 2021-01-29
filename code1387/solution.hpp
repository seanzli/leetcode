#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> nums;
        for (int i = lo; i <= hi; i++)
            nums.push_back(pair<int,int>(i, powerValue(i)));
        sort(nums.begin(), nums.end(), 
        [](pair<int,int> a, pair<int,int>b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        return nums[k-1].first;
    }

    int powerValue(int num){
        int count = 0;
        while (num!=1){
            if (num%2==0)
                num = num/2;
            else
                num = 3*num + 1;
            count++;
        }
        return count;
    }
};