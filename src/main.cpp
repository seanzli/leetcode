
#include "../code/code17_10/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,2,5,9,5,9,5,5,5};
    test->majorityElement(in);

    return 0;
}