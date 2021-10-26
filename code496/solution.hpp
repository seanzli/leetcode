#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            auto itr = std::find(nums2.begin(), nums2.end(), nums1[i]);
            while (itr != nums2.end()) {
                if (nums1[i] < *itr) {
                    res[i] = *itr;
                    break;
                }
                ++itr;
            }
        }
        return res;
    }
};