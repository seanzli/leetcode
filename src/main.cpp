
#include "../code150/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> s = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << test->evalRPN(s) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}