
#include "../code42/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector <int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << test->trap(nums)<<endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;        
    } */
    

    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}