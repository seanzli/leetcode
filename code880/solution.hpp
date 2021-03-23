#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string temp = "";
        int i = 0;
        while (i < S.size() && temp.size() < K) {
            if (S[i] >= '2' && S[i] <= '9') {
                string res = "";
                for (int j = 0; j < S[i] - '0'; j++)
                    res += temp;
                temp = res;
            } else {
                temp += S[i];
            }
            i++;
        }
        return temp.substr(K  - 1, 1);
    }
};