
#include "../code819/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    test->mostCommonWord(paragraph,banned);
    
    return 0;
}