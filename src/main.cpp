
#include "../code227/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "(3+5) / 2";
    cout << test->calculate(s) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}