#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
/*     int firstMissingPositive(vector<int>& nums) {
        int cur = 1;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]<=0)
                continue;
            hash[nums[i]]++;
            if (cur == nums[i])
            {
                cur++;
                while (hash.find(cur) != hash.end())
                    cur++;
            }
        }
        return cur;
    } */
    int firstMissingPositive(vector<int>& nums) {
        int min=1;

        while(min){
            bool flag=false;
            for(int it=0;it<nums.size();it++){
                if(nums[it]==min){
                    flag=true;
                    min++;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        return min;
    }

};