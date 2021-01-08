
#include "../code65/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    string in = argv[1];
    //vector<vector<int>> in = {{1,2,3},{4,5,6}};//,{4,2,1}};
    cout << test->isNumber(in) << endl;

 /*    while (out!=nullptr)
    {
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl; */

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
