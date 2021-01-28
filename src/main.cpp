
#include "../code299/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string secret = "1807";
    string guess = "7810";
    cout << test->getHint(secret, guess) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}