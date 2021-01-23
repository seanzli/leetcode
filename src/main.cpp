
#include "../code748/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string l = "Ah71752";
    vector<string> in = {"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"};
    cout << test->shortestCompletingWord(l, in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}