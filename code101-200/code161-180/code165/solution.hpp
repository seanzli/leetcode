#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

// class Solution {
// public:
//     int compareVersion(string version1, string version2) {
//         regex re("[.]");
//         vector<string> vec1(sregex_token_iterator(version1.begin(), version1.end(), re, -1), sregex_token_iterator());
//         vector<string> vec2(sregex_token_iterator(version2.begin(), version2.end(), re, -1), sregex_token_iterator());

//         int i=0;
//         for ( ; i<vec1.size() && i<vec2.size() ; i++){
//             int v1 = atoi(vec1[i].c_str());
//             int v2 = atoi(vec2[i].c_str());
//             if (v1 > v2)
//                 return 1;
//             else if (v1 < v2)
//                 return -1;
//         }

//         while (i<vec1.size()){
//             if (atoi(vec1[i].c_str())>0)
//                 return 1;
//             i++;
//         }

//         while (i<vec2.size()){
//             if (atoi(vec2[i].c_str())>0)
//                 return -1;
//             i++;
//         }
//         return 0;
//     }
// };

class Solution {
    int getVersionNum(const string& str, int& idx) {
        int res = 0;
        for (idx; idx < str.size(); ++idx) {
            if (str[idx] == '.')
                break;
            if (str[idx] == '0' && res == 0)
                continue;
            res = res * 10 + str[idx] - '0';
        }
        return res;
    }

    void getVersion(const string& str, vector<int>& vec) {
        vec.clear();
        for (int i = 0; i < str.size(); ++i) {
            vec.push_back(getVersionNum(str, i));
        }
        return;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        getVersion(version1, v1);
        getVersion(version2, v2);
        int i = 0;
        while (i < v1.size() && i < v2.size()) {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
            ++i;
        }
        while (i < v1.size()) {
            if (v1[i++] > 0)
                return 1;
        }
        while (i < v2.size()) {
            if (v2[i++] > 0)
                return -1;
        }
        return 0;
    }
};