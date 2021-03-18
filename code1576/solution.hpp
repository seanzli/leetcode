#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int n=s.length();
        char tmp='a';
        if(n==1 && s[0]=='?'){
            return "a";
        }
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                tmp='a';
                while(i-1>=0&&s[i-1]==tmp || i+1<n&&s[i+1]==tmp){
                    tmp++;
                }
                s[i]=tmp;
            }
        }
        return s;
    }
};