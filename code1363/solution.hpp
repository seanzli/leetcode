#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10), modulo(3);
        int sum = 0;
        for (int digit: digits) {
            ++cnt[digit];
            ++modulo[digit % 3];
            sum += digit;
        }

        int remove_mod = 0, rest = 0;
        if (sum % 3 == 1) {
            if (modulo[1] >= 1) {
                remove_mod = 1;
                rest = 1;
            }
            else {
                remove_mod = 2;
                rest = 2;
            }
        }
        else if (sum % 3 == 2) {
            if (modulo[2] >= 1) {
                remove_mod = 2;
                rest = 1;
            }
            else {
                remove_mod = 1;
                rest = 2;
            }
        }
        string ans;
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (rest && remove_mod == i % 3) {
                    --rest;
                }
                else {
                    ans += static_cast<char>(i + 48);
                }
            }
        }
        if (ans.size() && ans.back() == '0') {
            ans = "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};