
#include "../code953/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> words = {"kuvp","q"};
    string order = "ngxlkthsjuoqcpavbfdermiywz";
    test->isAlienSorted(words, order);
    
    return 0;
}