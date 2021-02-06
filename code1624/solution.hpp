#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> hash;
        int max_length = -1;
        for (int i=0; i<s.size(); i++){
            if (hash.find(s[i]) == hash.end())
                hash[s[i]] = i;
            else{
                max_length = max(max_length , i-hash[s[i]]-1);
            }
        }
        return max_length;
    }
};