#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int all = 0;
        int n = encoded.size()+1;
        vector<int> out(n);
        for (int i = 1; i<= n ; i++)
            all ^= i;
        int all_but_first = 0;
        for (int i = 1; i<encoded.size(); i+=2)
            all_but_first ^=encoded[i];
        out[0] = all ^ all_but_first;
        for (int i = 1; i<n;i++)
            out[i] = encoded[i-1]^out[i-1];
        return out;
    }
};