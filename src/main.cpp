
#include "../code1078/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string text = "alice is a good girl she is a good student";
    string a = "a";
    string b = "good";
    test->findOcurrences(text, a, b);
    
    return 0;
}