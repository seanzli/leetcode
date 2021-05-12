#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int i = 0, j = s.size();
        for (char c : s) {
            if (c == 'I') 
                res.push_back(i++);
            else 
                res.push_back(j--);
        }
        res.push_back(i);
        return res;
    }
};