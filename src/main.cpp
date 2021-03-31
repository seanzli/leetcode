
#include "../code830/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string in = "abbxxxxzzy";
    test->largeGroupPositions(in);
    return 0;
}