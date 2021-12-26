#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//    vector<string> findOcurrences(string text, string first, string second) {
//        string temp = "";
//        vector<string> str_vec;
//        for (char cur : text) {
//            if (cur == ' ' && temp.size() > 0) {
//                str_vec.push_back(temp);
//                temp = "";
//            } else {
//                temp += cur;
//            }
//        }
//        if (temp.size() > 0) {
//            str_vec.push_back(temp);
//        }
//
//        vector<string> out;
//        for (int i = 0; i < str_vec.size() - 2; i++) {
//            if (str_vec[i] == first && str_vec[i+1] == second)
//                out.push_back(str_vec[i+2]);
//        }
//        return out;
//    }
//};

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> vec;
        string cur = "";
        for (const auto& itr : text) {
            if (itr == ' ') {
                vec.push_back(cur);
                cur = "";
            } else {
                cur.push_back(itr);
            }
        }
        if (!cur.empty())
            vec.push_back(cur);
        vector<string> res;
        for (size_t i = 0; i + 2 < vec.size(); ++i) {
            if (vec[i] == first && vec[i + 1] == second)
                res.push_back(vec[i + 2]);
        }
        return res;
    }
};