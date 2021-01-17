
#include "../code139/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};

    cout << test->wordBreak(s, dict) << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    return 0;
}