
#include "../code224/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "(1+(4+5+2)-3)+(6+8)";

    cout << test->calculate(s) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}