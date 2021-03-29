
#include "../code373/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};

    test->kSmallestPairs(nums1, nums2, 3);
    return 0;
}