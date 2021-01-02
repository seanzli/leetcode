
#include "../code9/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //string s = "-91283472332";//argv[1];
    int num = 1234567899;//atoi(argv[1]);
    //cout << test->isPalindrome(num) << endl;
    if (test->isPalindrome(num))
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
    
    return 0;
}