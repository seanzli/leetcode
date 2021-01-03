#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        if (nums.size()<3)
            return out;

        sort(nums.begin(), nums.end());

        int iter_prev, iter_mid, iter_next, cur;
        int n = nums.size();
        for (iter_prev=0;iter_prev<n;iter_prev++)
        {
            if ((iter_prev>0) && (nums[iter_prev]==nums[iter_prev-1]))
                continue;
            iter_mid=iter_prev+1;
            iter_next = n-1;
            while (iter_mid < iter_next)
            {
                cur = (nums[iter_prev]) + (nums[iter_mid]) + (nums[iter_next]);
                if (cur== 0)
                {
                    out.push_back({nums[iter_prev], nums[iter_mid],nums[iter_next]});
                    while ((iter_mid < iter_next)&&(nums[iter_mid]==nums[iter_mid+1]))
                        iter_mid++;
                    while ((iter_mid < iter_next)&&(nums[iter_next]==nums[iter_next-1]))
                        iter_next--;
                    iter_mid++;
                    iter_next--;
                }
                else if (cur<0)
                {
                    iter_mid++;
                }
                else
                {
                    iter_next--;
                }
            }
        }
        return out;
    }
};