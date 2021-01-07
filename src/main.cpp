
#include "../code54/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> out =  test->spiralOrder(nums);

    for (int i = 0; i < out.size(); i++)
    {
        //cout << "/////" << endl;
        //for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i] << "," ; 
        }
    } 
    cout << endl;
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
