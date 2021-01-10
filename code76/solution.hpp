#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128]={};
        for(char c:t) cnt[c]++;
        int counter=t.size(),len=INT_MAX,start=0;
        for(int l=0,r=0;r<s.size();r++) {
            if(cnt[s[r]]-->0) counter--;
            while(counter==0) {
                if(r-l+1<len) {
                    start=l;
                    len=r-l+1;
                }
                if(cnt[s[l++]]++==0) counter++;
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};