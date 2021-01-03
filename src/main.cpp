
#include "../code16/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //vector<string> strs = {"reflower","flow","flight"};
    vector<int> nums = {1,1,1,1};
    cout<< test->threeSumClosest(nums,-100)<<endl;

    return 0;
}