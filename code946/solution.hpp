#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int idx_pop = 0;
        stack<int> hash;
        for (int idx_push = 0; idx_push < pushed.size(); ++idx_push) {
            hash.push(pushed[idx_push]);
            while (idx_pop < popped.size() && !hash.empty() && popped[idx_pop] == hash.top()) {
                hash.pop();
                ++idx_pop;
            }
        }
        return hash.empty();
    }
};