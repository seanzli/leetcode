
#include "../code28/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string haystack = "aaaaaa", needle = "aaaaab";
    cout << test->strStr(haystack,needle) << endl;

    return 0;
}