#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int main_value = nums[0], main_count = 1;
        for (int i = 1 ;i < nums.size(); i++){
            if (nums[i] == main_value)
                main_count++;
            else {
                main_count--;
                if (main_count ==0){
                    main_value = nums[i];
                    main_count = 1;
                }
            }
        }
        if (main_count > 0){
            main_count = 0;
            for (int i : nums){
                if (i == main_value)
                    main_count++;
            }
            if (main_count>nums.size()/2)
                return main_value;
        }
        return -1;
    }
};