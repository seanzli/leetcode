
#include "../code949/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {1, 2, 3, 4};
    cout << test->largestTimeFromDigits(in) << endl;
    return 0;
}