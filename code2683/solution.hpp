#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        std::unordered_map<char, int> hash;
        for (const auto& c : s1) {
            ++hash[c];
        }
        for (const auto& c : s2) {
            --hash[c];
        }
        for (const auto& itr : hash) {
            if (itr.second != 0)
                return false;
        }
        return true;
    }
};