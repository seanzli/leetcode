#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while(start < end){
            int cur = numbers[start] + numbers[end];
            if (cur == target)
                break;
            else if (cur > target)
                end--;
            else
                start++;
        }
        return vector<int> {start+1, end+1};
    }
};