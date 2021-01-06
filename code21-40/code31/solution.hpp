#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int vector_length = nums.size();
        int idx = 0, cur = 1000;
        for (idx = vector_length-1; idx >0; idx--)
        {
            if (nums[idx]-nums[idx-1]>0)
                break;
        }
        if (idx!=0)
        {//
            int cur_swap = idx;
            cur = nums[idx];
            for (int i = idx; i < vector_length; i++)
            {
                if ((nums[idx-1]<nums[i]) && (nums[i] < cur))
                {
                    cur_swap = i;
                }
            }
            cur = nums[cur_swap];
            nums[cur_swap] = nums[idx-1];
            nums[idx-1] = cur;
        }
        for (int i = idx; i < vector_length; i++)
        {
            for (int j = i+1; j < vector_length; j++)
            {
                if (nums[i]>nums[j])
                {
                    cur = nums[i];
                    nums[i] = nums[j];
                    nums[j] = cur;
                }
            }
        }
        return ;
    }
};