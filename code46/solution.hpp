#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void orderVector(vector<vector<int>> in, int num, vector<vector<int>> &out)
    {
        vector<int> cur;
        out.clear();
        int n = in[0].size();
        for (int i = 0; i < in.size(); i++)
        {
            cur = in[i];
            cur.push_back(num);
            out.push_back(cur);
            for (int j = 0; j < in[i].size(); j++)
            {
                cur[j] = num;
                cur[n] = in[i][j];
                out.push_back(cur);
                cur[j] = in[i][j];
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        int cur = 0;
        out.push_back({nums[0]});
        for (int i = 1; i < nums.size(); i++)
        {
            orderVector(out, nums[i], out);
        }
        return out;
    }
};