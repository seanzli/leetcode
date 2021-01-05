
#include "../code33/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "()(()";

    vector<int> words = {4,5,6,7,0,1,2};
    cout << test->search(words,1) << endl;
    

    return 0;
}