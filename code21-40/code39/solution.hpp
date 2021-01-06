#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> temp;
        vector<int> idx_lists;
        int idx=0, cur=0;
        vector<vector<int>> back_num;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        idx_lists.push_back(candidates.size()-1);
        while (idx_lists.size()>0){
            if (idx_lists[idx_lists.size()-1]<0)
            {
                idx_lists.pop_back();
                if (temp.size())
                {
                    sum = sum - temp[temp.size()-1];
                    temp.pop_back();
                }
                else{
                    sum = 0;
                    temp.clear();
                }
                continue;
            }

            idx = idx_lists[idx_lists.size()-1];
            if ((idx_lists.size()>1) && (idx <= idx_lists[idx_lists.size()-2]))
            {
                idx_lists.pop_back();
                if (temp.size())
                {
                    sum = sum - temp[temp.size()-1];
                    temp.pop_back();
                }
                else{
                    sum = 0;
                    temp.clear();
                }
                continue;
            }
            
            cur = candidates[idx];
            sum += cur; 
            temp.push_back(cur);

            idx_lists[idx_lists.size()-1]--;
            if (sum==target)
            {
                out.push_back(temp);
                sum = sum - temp[temp.size()-1];
                temp.pop_back();
            }
            else if (sum > target)
            {
                sum = sum - cur;
                temp.pop_back();
            }
            else
            {
                idx_lists.push_back(candidates.size()-1);
            }
        }
        return out;
    }
};