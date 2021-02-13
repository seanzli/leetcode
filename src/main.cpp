
#include "../code1658/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,1,4,2,3};
    cout << test->minOperations(in,5) << endl;

    return 0;
}