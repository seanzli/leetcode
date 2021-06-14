#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] > 0) return res;
            int left = i + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) ++left;
                else if (sum > 0) --right;
                else {
                    vector<int> tmp {nums[i], nums[left++], nums[right--]}; 
                    res.push_back(tmp);
                    while(left < right && nums[left] == nums[left - 1]) ++left;
                    while(left < right && nums[right] == nums[right + 1]) --right;  
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        vector<int> raw;
        vector<int> col;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    raw.push_back(i);
                    col.push_back(j);
                } 
            }
        }
        for (int raw_index : raw) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[raw_index][j] = 0;
            }
        }
        for (int col_index : col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col_index] = 0;
            }
        }
        return;
    }
};
