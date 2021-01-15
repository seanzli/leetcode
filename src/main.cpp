
#include "../code130/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char>> board = {{'O'}};
    test->solve(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << ",";
        }
        cout << endl;
    }
    
/*     while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl; */

    return 0;
}