
#include "../code/LCP_09/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> jump = {2,5,1,1,1,1};
    cout << test->minJump(jump) << endl;
    return 0;
}