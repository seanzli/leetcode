
#include "../code673/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> nums = {1,3,5,4,7};
    test->findNumberOfLIS(nums);
    return 0;
}