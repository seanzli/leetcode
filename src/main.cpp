
#include "../code1695/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {5,2,1,2,5,2,1,2,5};
    cout << test->maximumUniqueSubarray(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}