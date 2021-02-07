
#include "../code1452/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<vector<string>> in = {{"arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","zibvccaoayyihidztflj"},{"cffiqfviuwjowkppdajm","owqvnrhuzwqohquamvsz"},{"knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl"},{"arrtztkotazhufrsfczr","cffiqfviuwjowkppdajm"},{"arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl","zibvccaoayyihidztflj"}};
    test->peopleIndexes(in);

    return 0;
}