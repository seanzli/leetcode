#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hash; // ans count;
        for (int i : answers)
            hash[i]++;
        int res = 0;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            res += (itr->first + itr->second) / (itr->second + 1) * (itr->second + 1);
        }
        return res;
    }
};