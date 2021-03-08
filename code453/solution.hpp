#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        if (n < 2)
            return 0;
        while (nums[0] != nums.back()) {
            int dif = nums.back() - nums[0];
            for (int i = 0; i < n - 1; i++)
                nums[i] += dif;
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] <= nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                } else {
                    break;
                }
            }
            count += dif;
        }
        return count;
    }
}; */

/* class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int i = n - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;
    }
}; */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 0;i < nums.size();++i){
            moves += nums[i] - minValue;
        }
        return moves;
    }
};