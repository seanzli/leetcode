
#include "../code/code17_14/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,3,5,7,2,4,6,8};
    test->smallestK(in, 4);

    return 0;
}