
#include "../code91/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> nums1 = {1,2,1};

    string s= "2020";
    cout << test->numDecodings(s) << endl;

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