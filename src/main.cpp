
#include "../code403/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << test->canCross(stones) << endl;
    return 0;
}