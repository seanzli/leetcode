#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> ump;
        ump[0] = -1;
        int cnt = 0;
        int start = 0;
        int mxLen = 0;
        for(int i = 0; i < n; i ++){
            if(array[i][0] >= '0' && array[i][0] <= '9') cnt ++;
            else cnt --;
            if(ump.find(cnt) == ump.end()) ump[cnt] = i;
            else if(i - ump[cnt] > mxLen){
                mxLen = i - ump[cnt];
                start = ump[cnt] + 1;
            }
        }
        return vector<string>(array.begin() + start, array.begin() + start + mxLen);
    }
};
