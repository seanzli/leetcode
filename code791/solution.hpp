#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<bool> idx(T.size(),false);
        string out;
        for (char cur : S)
        {
            int i = -1;
            while ((i = T.find(cur, i+1)) != T.npos){
                out = out + T[i];
                idx[i]=true;
            }
        }
        for (int i = 0; i < idx.size(); i++)
        {
            if (idx[i] == false)
                out += T[i];
        }
        return out;
    }
};

class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&](const char a, const char b) {
            int i = S.find(a), j = S.find(b);
            return i < j;
        });
        return T;
    }
};