#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (char& itr : s) {
            if (itr >= 'A' && itr <= 'Z') {
                itr = itr - 'A' + 'a';
            }
        }
        return s;
    }
};