
#include "../code621/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<char> task = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
    cout << test->leastInterval(task, 2) << endl;
    return 0;
}