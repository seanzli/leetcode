#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        if(nums.size() == 1) return to_string(nums[0]);

        sort(nums.begin(), nums.end(), comparison); // 调用STL中的sort函数
        string result = "";
        for(int i : nums)
        {
            result += to_string(i);
        }
        if(result[0] == '0') return "0"; // 特殊case，全是0的时候应该输出0而不是00000
        return result;
    }
    static bool comparison(const int& a, const int& b)
    {
        string concatenation1 = to_string(a) + to_string(b);
        string concatenation2 = to_string(b) + to_string(a);
        
        return concatenation1 > concatenation2;
    }
};