#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(5, 0);
        for (const auto& itr : text) {
            switch (itr) {
                case 'a' : ++count[0]; break;
                case 'b' : ++count[1]; break;
                case 'l' : ++count[2]; break;
                case 'o' : ++count[3]; break;
                case 'n' : ++count[4]; break;
                default: break;
            }
        }
        count[2] = count[2] / 2;
        count[3] = count[3] / 2;

        return *min_element(count.begin(), count.end());
    }
};

