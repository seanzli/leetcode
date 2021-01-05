
#include "../code32/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "()(()";

    vector<int> words = {1,3,2};
    cout << test->longestValidParentheses(s) << endl;
    

    return 0;
}