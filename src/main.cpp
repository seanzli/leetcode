
#include "../code30/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "barfoofoobarthefoobarman";

    vector<string> words = {"bar","foo","the"};
    vector<int> out = test->findSubstring(s,words);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
    

    return 0;
}