
#include "../code332/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<string>> in = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    vector<string> out = test->findItinerary(in);

    return 0;
}