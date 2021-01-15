
#include "../code132/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    string s = "aab";
    cout << test->minCut(s) << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    
/*     while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl; */

    return 0;
}