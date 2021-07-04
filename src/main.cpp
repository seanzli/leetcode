
#include "../code/LC/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "aaaa";

    cout << test->longestPalindrome(s) << endl;

    return 0;
}