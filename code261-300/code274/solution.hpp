#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int m=citations.size();
        for(int i=0;i<m;i++){
            if(citations[i]>=m-i)return m-i;
        }
        return 0;
    }
};