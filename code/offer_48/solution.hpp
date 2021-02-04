#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alph(26, 0);
        int start = 0, end = 0;
        int max_length = 0;
        while (end < s.size()){
            if (alph[s[end]-'a']==0){
                alph[s[end]-'a'] = 1;
                max_length = max(max_length, end-start+1);
                end++;
            }
            else {
                while (s[start]!=s[end]){
                    alph[s[start]-'a'] = 0;
                    start++;
                }
                alph[s[start]-'a'] = 0;
                start++;
                max_length = max(max_length, end-start+1);
            }
        }
        return max_length;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> chars;
        int right = 0;
        for(int left = 0; left < s.size(); left ++){
            while(right < s.size() && !chars.count(s[right])){
                chars.insert(s[right]);
                right ++;
            }
            maxLen = max(maxLen, right - left);
            if(right == s.size()) break;
            chars.erase(s[left]);
        }
        return maxLen;
    }
};