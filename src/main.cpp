
#include "../code165/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string v1 = "1.01", v2 = "1.001";

    cout << test->compareVersion(v1, v2) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}