
#include "../code211/solution.hpp"

int main(int argc, char* argv[])
{
//    Solution *test = new Solution();

 //   cout << test->lengthOfLongestSubstring("") << endl;

    WordDictionary *test = new WordDictionary();
    test->addWord("at");
    test->addWord("and");
    test->addWord("an");
    test->addWord("add");
    cout << test->search("a") <<endl;
    cout << test->search(".at") <<endl;
    test->addWord("bat");
    cout << test->search(".at") <<endl;
    cout << test->search("an.") <<endl;
    cout << test->search("a.b.") <<endl;
    cout << test->search("b.") <<endl;
    cout << test->search("a.d") <<endl;
    cout << test->search(".") <<endl;

    return 0;
}