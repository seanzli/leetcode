#include <vector>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        int max_age = 0;
        for (int i = 0; i < ages.size(); i++){
            count[ages[i]] ++;
            max_age = max(ages[i], max_age);
        }

        int ret = 0;
        for (int i = 15; i <= max_age; i++){
            if (count[i] != 0){
                for (int j = i/2+8; j <= i; j++){
                    if (count[j] != 0)
                        ret += ( (j <= 100 || i >= 100) && i != j ) ? count[i]*count[j] :count[i]*(count[i]-1);
                 } 
            }             
        }
        return ret;
    }
};