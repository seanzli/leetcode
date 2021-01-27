
#include "../code274/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {3,0,6,1,5};
    cout << test->hIndex(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}