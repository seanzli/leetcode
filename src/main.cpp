
#include "../code/LCP_03/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> obs = {{4,2}};
    test->robot("URR", obs, 3, 2);
    return 0;
}