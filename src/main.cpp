
#include "../code101-200/code121-140/code140/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "catsanddog";
    vector<string> dic = {"cat", "cats", "and", "sand", "dog"};
    test->wordBreak(s, dic);
    return 0;
}