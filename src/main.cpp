
#include "../code35/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "()(()";

    vector<int> words = {1};
    vector<int> out = {test->searchInsert(words,1)};

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}