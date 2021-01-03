
#include "../code18/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //vector<string> strs = {"reflower","flow","flight"};
    //string str = "2";
    vector<int> nums= {1,0,-1,0,-2,2};
    int target = 0;
    test->fourSum(nums, target);

    return 0;
}