#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int first_Candidate = 0;
//         int second_Candidate = 0;
//         int num1 = 0;
//         int num2 = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == first_Candidate) num1 ++;
//             else if (nums[i] == second_Candidate) num2 ++;
//             else if (num1 == 0) {
//                 first_Candidate = nums[i];
//                 num1 ++;
//             }
//             else if (num2 == 0) {
//                 second_Candidate = nums[i];
//                 num2 ++;
//             }
//             else {
//                 num1 --;
//                 num2 --;
//             }
//         }
//         num1 = 0;
//         num2 = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == first_Candidate) num1 ++;
//             if (nums[i] == second_Candidate) num2 ++;
//         }
//         vector<int> result;
//         if (num1 > nums.size() / 3) result.push_back(first_Candidate);
//         if (num2 > nums.size() / 3 && first_Candidate != second_Candidate) result.push_back(second_Candidate);
//         return result;
//     }
// };

#include <unordered_map>
#include <map>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (const auto& itr : nums) {
            hash[itr]++;
        }
        vector<int> res;
        int n = nums.size() / 3;
        for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
            if (itr->second > n)
                res.push_back(itr->first);
        }
        return res;
    }
};