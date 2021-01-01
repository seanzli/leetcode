
#include "../code3/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "jbpnbwwd";
    
    cout << test->lengthOfLongestSubstring(s) << endl;

    return 0;
}