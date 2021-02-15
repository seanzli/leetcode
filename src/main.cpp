
#include "../code1071/solution.hpp"

#include <queue>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    string a = "ABCABC";
    string b = "ABC";
    cout<<test->gcdOfStrings(a,b) << endl;
    return 0;
}