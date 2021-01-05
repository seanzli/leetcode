
#include "../code38/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    
    for (int i = 1; i <= 30; i++)
    {
        cout <<i << " --  "<< test->countAndSay(i) << endl;
    }

   
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}