
#include "../code/code10_05/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> words = {"at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""};
    string s = "ta";
    test->findString(words, s);
    
    return 0;
}