
#include "../code179/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {999999998,999999997,999999999};

    cout << test->largestNumber(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}