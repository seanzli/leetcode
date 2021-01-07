
#include "../code58/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<vector<int>> nums = {{1,3},{6,5}};
    //vector<int> nums = {1};
    //vector<int> out =  test->canJump(nums);
    vector<int> newV = {2,5};
    string s = "a ";
    cout << test->lengthOfLastWord(s) << endl;

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
