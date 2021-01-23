#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<vector<int>> valid_box;
    int max_h = 0;
    
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end(), [](vector<int> a, vector<int> b){
            return accumulate(a.begin(),a.end(),0) < accumulate(b.begin(), b.end(), 0);
            });
        int n = box.size();
        dps(box, n);
        return max_h;
    }

    void dps(vector<vector<int>> &box, int n){
        if (n == 0){
            max_h = max(max_h, sumh());
            return;
        }
        for (int i = n -1; i >= 0; i--)
        {
            if (valid_box.empty()){
                valid_box.push_back(box[i]);
                dps(box, n-1);
                sumh();
                valid_box.pop_back();
            }
            else{
                if (bigger(valid_box.back(), box[i])){
                    valid_box.push_back(box[i]);
                    dps(box, n-1);
                    sumh();
                    valid_box.pop_back();
                }
            }
        }
        max_h = max(max_h, sumh());
        return;
    }

    bool bigger(vector<int> a, vector<int> b){
        return ((a[0]>b[0]) && (a[1]>b[1]) && (a[2]>b[2]));
    }

    int sumh(){
        int sum = 0;
        for (int i = 0; i < valid_box.size(); i++)
            sum += valid_box[i][2];
        return sum;
    }
};

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        vector<int> f(n + 1);
        sort(box.begin(), box.end());
        int res = 0;
        for (int i = 0; i < n; i ++) {
            f[i] = box[i][2];
            res = max(res, f[i]);
            for (int j = 0; j < i; j ++) {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
                    f[i] = max(f[i], f[j] + box[i][2]);
                    res = max(res, f[i]);
                }
            }
        }
        return res;
    }
};