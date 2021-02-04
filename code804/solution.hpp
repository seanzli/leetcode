#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> hash;
        string temp;
        for (string i : words){
            temp = "";
            for (char cur : i){
                temp += map[cur-'a'];
            }
            hash.insert(temp);
        }
        return temp.size();
    }
};