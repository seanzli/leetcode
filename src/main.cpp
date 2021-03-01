
#include "../code101-200/code121-140/code127/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string a = "hot";
    string b = "dog";
    vector<string> wordList = {a,b};
    test->ladderLength(a,b, wordList);
    return 0;
}