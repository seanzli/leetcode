#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (const auto& str : logs) {
            if (str == "../") {
                res--;
                if (res < 0)
                    res = 0;
            } else if (str == "./") {
                ;
            } else {
                res++;
            }
        }
        return res;
    }
};