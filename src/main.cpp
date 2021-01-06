
#include "../code44/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    string s = "adceb";
    string p = "a*c*b";

    cout << test->isMatch(s,p)<<endl;    

    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}