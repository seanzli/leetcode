#include <cstdio>
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <queue>

using namespace std;

//class Solution {
//public:
//    int isPrefixOfWord(string sentence, string searchWord) {
//        istringstream ss(sentence);
//        string str;
//        for (int i = 1; ss >> str; i ++)
//            if (str.find(searchWord) == 0) return i;
//        return -1;
//    }
//};

class Solution {
    bool isPrefix(const string& sentence, int& i, const string& searchWord) {
        int idx = 0;
        for (; i < sentence.size() && idx < searchWord.size(); ++i, ++idx) {
            if (sentence[i] == ' ' || sentence[i] != searchWord[idx])
                return false;
        }
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = 1;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == searchWord[0] && isPrefix(sentence, i, searchWord))
                return res;


            for (; i < sentence.size(); ++i) {
                if (sentence[i] == ' ') {
                    ++res;
                    break;
                }
            }
        }
        return -1;
    }
};