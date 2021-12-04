#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26, 0);
        for (char& itr : magazine) {
            ++mag[itr - 'a'];
        }
        for (char& itr : ransomNote) {
            if (mag[itr - 'a']-- == 0)
                return false;
        }
        return true;
    }
};