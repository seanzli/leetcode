
#include "../code215/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {3,2,1,5,6,4};
    cout << test->findKthLargest(in,2) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}