
#include "../code645/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {2,4,2,1};
    test->findErrorNums(in);
    return 0;
}