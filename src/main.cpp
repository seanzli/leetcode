
#include "../code/code17_08/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> h = {1,2,3,4};
    vector<int> w = {4,3,2,1};
    cout << test->bestSeqAtIndex(h, w) << endl;
    return 0;
}