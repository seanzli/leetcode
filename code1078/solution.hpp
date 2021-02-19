#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string temp = "";
        vector<string> str_vec;
        for (char cur : text) {
            if (cur == ' ' && temp.size() > 0) {
                str_vec.push_back(temp);
                temp = "";
            } else {
                temp += cur;
            }
        }
        if (temp.size() > 0) {
            str_vec.push_back(temp);
        }

        vector<string> out;
        for (int i = 0; i < str_vec.size() - 2; i++) {
            if (str_vec[i] == first && str_vec[i+1] == second)
                out.push_back(str_vec[i+2]);
        }
        return out;
    }
};