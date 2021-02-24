#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<string> back_up;
    string res = "";
    vector<bool> flag;
public:
    string largestTimeFromDigits(vector<int>& arr) {
        flag = vector<bool>(4, false);
        dfs(arr, 0, res);
        if (back_up.size()) {
            res = *max_element(back_up.begin(), back_up.end());
            return res.substr(0,2) + ":" + res.substr(2,2);
        } else {
            return "";
        }
    }
    bool dfs(vector<int>& arr, int idx, string &res) {
        switch (idx) {
            case 0: break;
            case 1: {
                if (res[0] > '2')
                    return false;
                break;
            }
            case 2: {
                if (res[0] == '2' && res[1] > '3')
                    return false;
                break;
            }
            case 3: {
                if (res[2] > '5')
                    return false;
                break;
            }
            case 4: {
                back_up.push_back(res);
                return true;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (flag[i] == false) {
                res += (arr[i] + '0');
                flag[i] = true;
                dfs(arr, idx + 1, res);
                flag[i] = false;
                res.pop_back();
            }
        }
        return false;
    }
};

/* class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        do {
            if (arr[0]*10 + arr[1] < 24 && arr[2]*10 + arr[3] < 60)
                return to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
        } while (prev_permutation(arr.begin(), arr.end()));
        return "";
    }
}; */