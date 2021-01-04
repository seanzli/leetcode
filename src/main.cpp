
#include "../code26/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {0,0,1,1,1,2,2,3,3,4};
    cout << test->removeDuplicates(in) << endl;

    return 0;
}