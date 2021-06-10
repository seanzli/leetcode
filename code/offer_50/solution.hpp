#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> hash;
        for (char itr : s)
            hash[itr]++;
        for (char itr : s) {
            if (hash[itr] == 1)
                return itr;
        }
        return ' ';
    }
};