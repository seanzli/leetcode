
#include "../code1208/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "abcd";
    string t = "cdef";

    cout << test->equalSubstring(s,t,3) << endl;

    return 0;
}