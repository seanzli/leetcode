#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     unordered_map<char, int> hash;
//     vector<char> vec;
//     string shortestCompletingWord(string licensePlate, vector<string>& words) {
//         char cur;
//         for (int i = 0; i< licensePlate.size(); i++)
//         {
//             if ((licensePlate[i]>='a') && (licensePlate[i]<='z')){
//                 hash[licensePlate[i]]++;
//                 if (hash[licensePlate[i]] == 1)
//                     vec.push_back(licensePlate[i]);
//             }
//             if ((licensePlate[i]>='A') && (licensePlate[i]<='Z')){
//                 hash[licensePlate[i]-'A'+'a']++;
//                 if (hash[licensePlate[i]-'A'+'a'] == 1)
//                     vec.push_back(licensePlate[i]-'A'+'a');
//             }
//         }

//         int short_length = INT_MAX;
//         int short_idx = 0;

//         for (int i = 0; i< words.size(); i++)
//         {
//             if (words[i].size() < vec.size())
//                 continue;
//             if (countChar(words[i])){
//                 if (words[i].size() < short_length){
//                     short_idx = i;
//                     short_length = words[i].size();
//                 }
//             }
//         }
//         return words[short_idx];
//     }

//     bool countChar(string s){
//         char cur;
//         int num;
//         for (int i = 0; i<vec.size(); i++){
//             cur = vec[i];
//             num = hash[cur];
//             string cur_s = s;
//             for (int j = 0; j < num; j++)
//             {
//                 if (cur_s.find(cur) == cur_s.npos)
//                     return false;
//                 cur_s = cur_s.substr(cur_s.find(cur)+1);
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> license_count(26, 0);
        for (int i = 0; i < licensePlate.size(); ++i) {
            if (isupper(licensePlate[i])) {
                ++license_count[licensePlate[i] - 'A'];
            } else if (islower(licensePlate[i])) {
                ++license_count[licensePlate[i] - 'a'];
            }
        }
        for (int i = 0; i < license_count.size(); ++i)
            std::cout << license_count[i] << " ,";
        std::cout << "\n";

        int idx = -1, len = 15;
        for (int i = 0; i < words.size(); ++i) {
            if (checkString(license_count, words[i]) && words[i].size() < len) {
                len = words[i].size();
                idx = i;
            }
        }
        if (idx == -1)
            return "";
        return words[idx];
    }
    bool checkString(const vector<int>& count, const string& str) {
        
        vector<int> cur(26, 0);
        for (int i = 0; i < str.size(); ++i) {
            ++cur[str[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (cur[i] < count[i])
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     string shortestCompletingWord(string licensePlate, vector<string> &words) {
//         array<int, 26> cnt{};
//         for (char ch : licensePlate) {
//             if (isalpha(ch)) {
//                 ++cnt[tolower(ch) - 'a'];
//             }
//         }
//         int idx = -1;
//         for (int i = 0; i < words.size(); ++i) {
//             array<int, 26> c{};
//             for (char ch : words[i]) {
//                 ++c[ch - 'a'];
//             }
//             bool ok = true;
//             for (int j = 0; j < 26; ++j) {
//                 if (c[j] < cnt[j]) {
//                     ok = false;
//                     break;
//                 }
//             }
//             if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
//                 idx = i;
//             }
//         }
//         return words[idx];
//     }
// };