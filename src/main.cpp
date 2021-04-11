
#include "../code/code04_01/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> gra = {{0, 1}, {0, 2}, {1, 2}, {1, 2}};
    cout << test->findWhetherExistsPath(3, gra, 0, 2) << endl;
    return 0;
}