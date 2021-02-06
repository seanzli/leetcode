#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<int> num;
public:
    int magicalString(int n) {
        num.push_back(1);
        num.push_back(2);
        num.push_back(2);
        if (n==0)   return 0;
        if (n<3)    return 1;
        int idx = 2, count = 1;
        int cur = 1;
        while (num.size()<n){
            if (cur == 1){
                if ((num.size() + num[idx])>=n){
                    count = count + n - num.size();
                    return count;
                }
                else
                    count = count + num[idx];
                    
                for (int j = 0; j<num[idx]; j++){
                    num.push_back(cur);
                }
                cur = 3 - cur;
                idx++;
            } else {
                for (int j = 0; j<num[idx]; j++){
                    num.push_back(cur);
                }
                cur = 3 - cur;
                idx++;
            }
        }
        return count;
    }
};