#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        vector<int> pre, next;
        if (numRows==0) return out;
        out.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            pre.clear();
            pre.push_back(0);
            pre.insert(pre.end(),out.back().begin(),out.back().end());
            pre.push_back(0);
            next.clear();
            for (int j = 0; j < pre.size()-1; j++)
                next.push_back(pre[j]+pre[j+1]);
            out.push_back(next);
        }
        return out;
    }
};