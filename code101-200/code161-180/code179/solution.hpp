#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>

using namespace std;

/* class Solution {
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
}; */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int & b) {
            string s_a = to_string(a);
            string s_b = to_string(b);
            return s_a + s_b > s_b + s_a;
        });

        string res = "";
        for (int itr : nums) {
            res += to_string(itr);
        }
        if (res[0] == '0')
            return "0";
        return res;
    }
};