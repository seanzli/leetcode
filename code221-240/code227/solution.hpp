#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* class Solution {
private:

public:
    int calculate(string s) {
        int i = 0;
        return calcS(s, i);
    }

    int calcS(string &s, int &i){
        vector<int> nums;
        vector<char> opt;
        int out = 0, cur=0, flag=0, signal=1;
        for (; i < s.size(); i++)
        {
            if ((s[i]>='0')&&(s[i]<='9'))
                cur = cur*10-'0'+s[i];
            else if ((s[i]=='+')||(s[i]=='-')){
                if (flag==1)
                    cur = calc(cur, nums, opt);
                nums.push_back(cur);
                cur=0;
                opt.push_back(s[i]);
                flag=0;
            }
            else if ((s[i] == '*')||(s[i]=='/')){
                if (flag==1)
                    cur = calc(cur, nums, opt);
                nums.push_back(cur);
                opt.push_back(s[i]);
                flag=1;
                cur=0;
            }
            else if (s[i]=='('){
                i++;
                cur = calcS(s, i);
                if (flag==1)
                    cur = calc(cur, nums, opt);
                flag=0;
            }
            else if (s[i]==')')
                break;
            else if (s[i]==' ')
                continue;
        }
        if (flag==1)
            cur = calc(cur, nums, opt);
        nums.push_back(cur);
        return calcStack(nums, opt);
    }
    int calc(int cur, vector<int> &nums, vector<char> &opt){
        int pre = nums.back();nums.pop_back();
        if (opt.back() == '*'){
            opt.pop_back();
            return (pre*cur);
        }
        else{
            opt.pop_back();
            return (pre/cur);
        }
    }

    int calcStack(vector<int> &nums, vector<char> &opt){
        if (!nums.size())
            return 0;
        int out = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (opt[i-1]=='+')
                out += nums[i];
            else
                out -= nums[i];
        }
        return out;
    }
}; */

#include <numeric>

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};