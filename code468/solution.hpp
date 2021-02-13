#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        vector<string> v4 = split(IP, '.');
        vector<string> v6 = split(IP, ':');
        if (v4.size()==4){
            for (string cur : v4){
                if (cur.size()>4 || cur.size() <1)
                    return "Neither";
                if (cur.size() >1 && cur[0]=='0')
                    return "Neither";
                if (atoi(cur.c_str()) > 255)
                    return "Neither";
                for (char i : cur){
                    if (i >='0' && i<='9')
                        continue;
                    return "Neither";
                }
            }
            return "IPv4";
        }
        if (v6.size()==8){
            for (string cur : v6){
                if (cur.size()>5 || cur.size()<1)
                    return "Neither";
                for (char i : cur){
                    if ((i >= 'a' && i <= 'f') ||
                        (i >= 'A' && i <= 'F') ||
                        (i >= '0' && i <= '9'))
                        continue;
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
    vector<string> split(string IP, char sp){
        vector<string> out;
        int right = 0;
        while ((right = IP.find(sp)) != IP.npos){
            out.push_back(IP.substr(0, right));
            IP = IP.substr(right+1);
        }
        out.push_back(IP);
        return out;
    }
};