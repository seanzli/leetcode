
#include "../code34/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "()(()";

    vector<int> words = {5,7,7,8,8,10};
    vector<int> out = test->searchRange(words,6);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}