#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, end = 0;
        int max_length = 0;
        int sum_cost = 0;
        while (end<s.size()){
            sum_cost += abs(t[end]-s[end]);
            if (sum_cost > maxCost){
                while (sum_cost > maxCost && start < end){
                    sum_cost -= abs(t[start]-s[start]);
                    start++;
                }
            }
            if (sum_cost <= maxCost)
                max_length = max(max_length, end-start+1);
            end++;
        }
        return max_length;
    }
};