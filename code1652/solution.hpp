#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) {
            return ans;
        } else if (k < 0) {
            for (int i = 0; i < code.size(); ++i) {
                int num = 0;
                for (int j = 0, index = i; j < -k; ++j) {
                    num += code[(--index + n) % n];
                }
                ans[i] = num;
            }
        } else {
            for (int i = 0; i < code.size(); ++i) {
                int num = 0;
                for (int j = 0, index = i; j < k; ++j) {
                    num += code[(++index) % n];
                }
                ans[i] = num;
            }
        }
        return ans;
    }
};