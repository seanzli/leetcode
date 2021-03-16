#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> mp;
        mp[0]++;
        int ans = 0, s = 0;
        for(auto x:A){
            s += x;
            ans += mp[s - S];
            mp[s]++;
        }
        return ans;
    }
};