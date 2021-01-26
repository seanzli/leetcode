#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int index = 0;
        int num = 0;
        while(index < input.size() && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';
        if(index == input.size())
            return {num};
        vector<int> ans;
        for(int i = 0; i < input.size(); i++){
            if(isOp(input[i])){
                vector<int> result1 = diffWaysToCompute(input.substr(0,i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for(int r1 : result1){
                    for(int r2 : result2){
                        ans.push_back(calculate(r1,input[i],r2));
                    }
                }
            }
        }
        return ans;
    }
    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    int calculate(const int& num1, const char& op, const int& num2){
        if(op == '+')
            return num1 + num2;
        else if(op == '-')
            return num1 - num2;
        else
            return num1 * num2;
    }
};