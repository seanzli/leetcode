#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0 && popped.size() == 0)
            return true;
        int idx = 0;
        stack<int> hash;
        for (int i = 0; i < pushed.size(); i++) {
            hash.push(pushed[i]);
            while (hash.size() && hash.top() == popped[idx]) {
                hash.pop();
                idx++;
            }
        }
        return hash.size() == 0 && idx == popped.size();
    }
};