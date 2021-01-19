
#include "../code151/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "  hello world  ";
    cout << test->reverseWords(s) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}