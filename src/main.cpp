
#include "../code1090/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> value = {9,8,8,7,6};
    vector<int> labels = {0,0,0,1,1};
    test->largestValsFromLabels(value, labels, 3, 2);
    return 0;
}