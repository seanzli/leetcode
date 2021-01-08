
#include "../code60/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    //vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    //vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    string out =  test->getPermutation(9,9);

    cout << out << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        //cout << "/////" << endl;
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << "," ; 
        }
        cout << endl;
    }  */
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
