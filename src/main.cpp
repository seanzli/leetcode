
#include "../code937/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> in = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    test->reorderLogFiles(in);
    return 0;
}