#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* class Solution {
public:
    string vector2string(vector<int>& in)
    {
        string s;
        for (int i = in.size()-1; i >=0; i--)
        {
            s += to_string(in[i]);
        }
        return s;
    }
    void orderVector(vector<vector<int>> in, int num, vector<vector<int>> &out)
    {
        vector<int> cur;
        out.clear();
        int n = in[0].size();
        unordered_map<string,int> hash;
        string cur_s;
        for (int i = 0; i < in.size(); i++)
        {
            cur = in[i];
            cur.push_back(num);
            cur_s = vector2string(cur);
            if(hash.find(cur_s)==hash.end())
            {
                out.push_back(cur);
                hash[cur_s]++;
            }
            for (int j = 0; j < in[i].size(); j++)
            {
                cur[j] = num;
                cur[n] = in[i][j];
                cur_s = vector2string(cur);
                if(hash.find(cur_s)==hash.end())
                {
                    out.push_back(cur);
                    hash[cur_s]++;
                }
                cur[j] = in[i][j];
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do {
            ret.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};