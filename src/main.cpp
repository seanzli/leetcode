
#include "../code992/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,2,1,2,3};
    test->subarraysWithKDistinct(in,2);

    return 0;
}