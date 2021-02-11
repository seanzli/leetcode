
#include "../code874/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> command = {4,-1,3};
    vector<vector<int>> obstacles;
    cout << test->robotSim(command, obstacles) << endl;

    return 0;
}