#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>

using namespace std;

// class Solution {
// public:
//     string getHint(string secret, string guess) {
//         vector<int> q(10,0),w(10,0);
//         int a=0,b=0;
//         for (int i=0;i<secret.length();i++){
//             if (secret[i]==guess[i]){
//                 a++;
//             }else{
//                 q[secret[i]-'0']++;
//                 w[guess[i]-'0']++;
//             }
//         }
//         for (int i=0;i<10;i++){
//             b+=min(q[i],w[i]);
//         }
//         return to_string(a)+"A"+to_string(b)+"B";
//     }
// };

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> sec(10, 0), gue(10, 0);
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i])
                ++a;
            else {
                ++sec[secret[i] - '0'];
                ++gue[guess[i] - '0'];
            }
        }

        for (int i = 0; i < 10; ++i) {
            b += min(sec[i], gue[i]);
        }

        return to_string(a) + "A" + to_string(b) + "B";
    }
};