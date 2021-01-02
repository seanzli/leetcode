
#include "../code11/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //string s = "-91283472332";//argv[1];
    vector<int> height = {1,8,6,2,5,4,8,3,7};//atoi(argv[1]);

    cout <<test->maxArea(height)<<endl;

    return 0;
}