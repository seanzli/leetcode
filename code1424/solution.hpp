#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> out;
        int row = nums.size();
        int idx = 0;
        while (1){
            int n = out.size();
            for (int i = idx; i >= 0; i--){
                if (i < row &&  idx-i < nums[i].size())
                    out.push_back(nums[i][idx-i]);
            }
            idx++;
            if (n == out.size())
                break;
        }
        return out;
    }
};