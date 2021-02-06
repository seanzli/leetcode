
#include "../code1423/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {9,7,7,9,7,7,9};

    cout << test->maxScore(in,7) << endl;

    return 0;
}