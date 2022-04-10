#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    int uniqueMorseRepresentations(vector<string>& words) {
//        vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
//        unordered_set<string> hash;
//        string temp;
//        for (string i : words){
//            temp = "";
//            for (char cur : i){
//                temp += map[cur-'a'];
//            }
//            hash.insert(temp);
//        }
//        return temp.size();
//    }
//};

static const string g_map[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> _set;
        for (const auto& str : words) {
            string cur = trans(str);
            if (_set.count(cur) == 0)
                _set.insert(cur);
        }
        return _set.size();
    }

    string trans(const string& word) {
        string out = "";
        for (const auto& ch : word) {
            out += g_map[ch - 'a'];
        }
        return out;
    }
};