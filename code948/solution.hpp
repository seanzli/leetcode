#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    int max_point = 0;
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int left = 0, right = tokens.size() - 1;
        if (tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());
        dfs(tokens, left, right, P);
        return max_point;
    }
    void dfs(vector<int>& tokens, int left ,int right, int power) {
        int cur_point = 0;
        int _left = left;
        int _power = power;
        if (left >= tokens.size() || power < tokens[left] || left > right)
            return;
        while (power >= tokens[left] && left <= right) {
            cur_point++;
            power -= tokens[left];
            left++;
        }
        max_point = max(max_point, cur_point);
        dfs(tokens, _left + 1, right - 1, _power - tokens[_left] + tokens[right]);
        return;
    }
};

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        int size=tokens.size();
        int score=0,res=0;
        sort(tokens.begin(),tokens.end(),less<int>());
        int left=0,right=size-1;
        while(left<=right){
            while(left<=right&&tokens[left]<=p){
                p-=tokens[left];left++;
                score++;
                res=max(res,score);
            }
            if(left<=right&&score){
                score--;
                p+=tokens[right--];
            }
            else if(!score)return res;
        }
        return res;
    }
};