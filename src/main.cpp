
#include "../code1049/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> data = {31,26,33,21,40};
    cout << test->lastStoneWeightII(data) << endl;
    return 0;
}