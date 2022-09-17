#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int maxLengthBetweenEqualCharacters(string s) {
//        unordered_map<char,int> hash;
//        int max_length = -1;
//        for (int i=0; i<s.size(); i++){
//            if (hash.find(s[i]) == hash.end())
//                hash[s[i]] = i;
//            else{
//                max_length = max(max_length , i-hash[s[i]]-1);
//            }
//        }
//        return max_length;
//    }
//};

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstIndex(26, -1);
        int maxLength = -1;
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex[s[i] - 'a'] < 0) {
                firstIndex[s[i] - 'a'] = i;
            } else {
                maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
            }
        }
        return maxLength;
    }
};