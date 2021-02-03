#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // 插入位置原位置+后面index <= i的元素个数
        int N = nums.size();
        vector<int> reindex = index;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(index[j] <= reindex[i]) 
                    reindex[i]++;
            }
        }
    
        vector<int> res(N, 0);
        for(int i = 0; i < N; i++){
            // cout << reindex[i] << " ";
            res[reindex[i]] = nums[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> r;
        for (unsigned i = 0; i < nums.size(); ++i) {
            r.insert(r.begin() + index[i], nums[i]);
        }
        return r;
    }
};