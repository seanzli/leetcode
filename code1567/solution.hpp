#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int max_length = 0;
        int idx0 = -1, idx_negitive = -1, idx_positive = -1;
        int count = 0;
        for (int i=0; i< nums.size(); ++i){
            if (nums[i]==0){
                count = 0;
                idx0 = i;
                idx_negitive = -1;
                idx_positive = -1;
            }
            else if (nums[i] < 0){
                count++;
                if (idx_negitive == -1)
                    idx_negitive = i;
            }
            if (count%2==0)
                max_length = max(max_length, i-idx0);
            else if (idx_negitive >=0)
                max_length = max(max_length, i-idx_negitive);
        }
        return max_length;
    }
}; */

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<int> positive(nums.size(), 0);
        vector<int> negitive(nums.size(), 0);
        if (nums[0] > 0)
            positive[0] = 1;
        if (nums[0] < 0)
            negitive[0] = 1;
        for (int i = 1;i<nums.size();i++){
            if (nums[i] > 0){
                positive[i] = positive[i-1] + 1;
                negitive[i] = negitive[i-1] > 0 ?  negitive[i-1] +1 : 0;
            }
            else if (nums[i] <0){
                positive[i] = negitive[i-1] > 0 ? negitive[i-1] + 1 : 0;
                negitive[i] = positive[i-1] + 1;
            }
            else{
                positive[i] = 0;
                negitive[i] = 0;
            }
        }
        return *max_element(positive.begin(), positive.end());
    }
};