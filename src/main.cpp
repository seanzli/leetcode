
#include "../code322/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> nums = {2};
    cout << test->coinChange(nums, 3) << endl;
    return 0;
}