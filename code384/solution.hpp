#include <cstdio>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution {
    vector<int> orj, res;
    int n;
public:
    Solution(vector<int>& nums) {
        orj = nums;
        res = nums;
        n = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        res = orj;
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < n; i++) {
            int j = (rand() % (n-i))+ i;
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */