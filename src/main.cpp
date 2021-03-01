
#include "../code347/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {1,1,1,1,2,2,3,3,3};
    test->topKFrequent(in,2);
    return 0;
}