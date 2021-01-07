
#include "../code51/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<string> strs = {"tea","and","ace","ad","eat","dans"};
    vector<vector<string>>  out =  test->solveNQueens(4);// << endl;

    for (int i = 0; i < out.size(); i++)
    {
        cout << "/////" << endl;
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << endl;
        }
    }
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
