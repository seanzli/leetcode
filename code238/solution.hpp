#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L = nums;
        for (int i = 1; i < L.size(); i++)
            L[i] = L[i-1]*L[i];

        int R = 1;
        for (int i = L.size()-1; i >=1 ; i--)
        {
            L[i] = L[i-1]*R;
            R=R*nums[i];
        }
        L[0] = R;
        return L;
    }
};