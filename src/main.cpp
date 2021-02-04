
#include "../code804/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> words = {"gin", "zen", "gig", "msg"};

    cout << test->uniqueMorseRepresentations(words) << endl;

    return 0;
}