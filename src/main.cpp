
#include "../code930/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {1,0,1,0,1};
    test->numSubarraysWithSum(in, 2);
    return 0;
}