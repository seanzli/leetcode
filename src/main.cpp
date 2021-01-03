
#include "../code15/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //vector<string> strs = {"reflower","flow","flight"};
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> out =test->threeSum(nums);
    //cout << << endl;

    return 0;
}