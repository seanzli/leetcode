#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        regex re("[.]");
        vector<string> vec1(sregex_token_iterator(version1.begin(), version1.end(), re, -1), sregex_token_iterator());
        vector<string> vec2(sregex_token_iterator(version2.begin(), version2.end(), re, -1), sregex_token_iterator());

        int i=0;
        for ( ; i<vec1.size() && i<vec2.size() ; i++){
            int v1 = atoi(vec1[i].c_str());
            int v2 = atoi(vec2[i].c_str());
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
        }

        while (i<vec1.size()){
            if (atoi(vec1[i].c_str())>0)
                return 1;
            i++;
        }

        while (i<vec2.size()){
            if (atoi(vec2[i].c_str())>0)
                return -1;
            i++;
        }
        return 0;
    }
};