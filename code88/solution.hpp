#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int idx1 = m-1;
        int idx2 = n-1;
        if (m == 0){
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        if (n == 0){
            return;
        }
        int idx = m+n-1;
        while (idx1>=0 && idx2>=0){
            if (nums1[idx1] < nums2[idx2])
            {
                nums1[idx] = nums2[idx2];
                idx2--;idx--;
            }
            else{
                nums1[idx] = nums1[idx1];
                idx1--; idx--;
            }
        }
        if (idx2>=0)
        {
            for (int i = 0; i <= idx2; i++)
                nums1[i] = nums2[i];
        }
        return;
    }
};