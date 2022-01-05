#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//    string modifyString(string s) {
//        int n=s.length();
//        char tmp='a';
//        if(n==1 && s[0]=='?'){
//            return "a";
//        }
//        for(int i=0;i<n;i++){
//            if(s[i]=='?'){
//                tmp='a';
//                while(i-1>=0&&s[i-1]==tmp || i+1<n&&s[i+1]==tmp){
//                    tmp++;
//                }
//                s[i]=tmp;
//            }
//        }
//        return s;
//    }
//};

class Solution {
public:
    string modifyString(string s) {
        size_t size = s.size();
        for (size_t i = 0; i < size; ++i) {
            if (s[i] == '?') {
                s[i] = 'a';
                if (i > 0 && s[i] == s[i - 1])
                    ++s[i];
                if (i < size - 1 && s[i] == s[i + 1])
                    ++s[i];
                if (i > 0 && s[i] == s[i - 1])
                    ++s[i];
            }
        }
        return s;
    }
};