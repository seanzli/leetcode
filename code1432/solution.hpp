#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        // max
        string in = to_string(num);
        char change_cha = 'a';
        for (int i = 0; i < in.size(); i++){
            if (in[i] != '9'){
                change_cha = in[i];
                break;
            }
        }
        if (change_cha != 'a'){
            for (int i = 0; i < in.size(); i++)
            {
                if (in[i] == change_cha)
                    in[i] = '9';
            }
        }
        int max_value = atoi(in.c_str());

        //min
        in = to_string(num);
        change_cha = 'a';
        if (in[0] == '1'){
            for (int i = 1; i < in.size(); i++){
                if (in[i]=='1')
                    continue;
                if (in[i] != '0'){
                    change_cha = in[i];
                    break;
                }
            }
            if (change_cha !='a'){
                for (int i = 0; i < in.size(); i++)
                {
                    if (in[i] == change_cha)
                        in[i] = '0';
                }                
            }
        }
        else{
            change_cha = in[0];
            for (int i = 0; i < in.size(); i++)
            {
                if (in[i] == change_cha)
                    in[i] = '1';
            }
        }
        int min_value = atoi(in.c_str());
        return max_value - min_value;
    }
};