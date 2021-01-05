
#include "../code31/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "barfoofoobarthefoobarman";

    vector<int> words = {1,3,2};
    test->nextPermutation(words);

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
    

    return 0;
}