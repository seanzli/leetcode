#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bit_s(n);
        string str = bit_s.to_string();
        int max_dis = 0;
        if (bit_s.count() < 2)
            return 0;
        int idx = -1;
        for (int i=0; i<str.size(); i++){
            if (str[i] == '1'){
                if (idx == -1){
                    idx = i;
                } else {
                    max_dis = max(max_dis, i-idx);
                    idx = i;
                }
            }
        }
        return idx;
    }
};