
#include "../code10/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

/*     string s = argv[0];
    string p = argv[1]; */
    string s = "aaa";
    string p = "ab*ac*a";

    bool out = test->isMatch(s, p);

    cout << out << endl;
    return out;
}