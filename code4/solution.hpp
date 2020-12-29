#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int idx1, idx2;

        for (int i = 0; i < nums2.size(); i++)
            nums1.push_back(nums2.at(i));
        
        sort(nums1.begin(), nums1.end());

        if (nums1.size()<1)
            return 0.0;

        if (nums1.size()/2*2==nums1.size())
        {
            idx1 = (nums1.size()/2-1) > 0?(nums1.size()/2-1):0;
            idx2 = nums1.size()/2;
            return (nums1[idx1]+nums1[idx2])/2.0;
        }
        else
        {
            return nums1[nums1.size()/2];
        }
    }
};