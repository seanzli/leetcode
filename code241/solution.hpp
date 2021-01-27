#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i]=='+' || input[i]=='-' || input[i] =='*'){
                vector<int> left  = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (int l : left)
                {
                    for (int r : right)
                    {
                        switch(input[i]){
                            case '+': result.push_back(l+r);break;
                            case '-': result.push_back(l-r);break;
                            case '*': result.push_back(l*r);break;
                            default: break;
                        }
                    }
                }
            }
        }
        if (result.size()==0)
            result.push_back(atoi(input.c_str()));
        return result;
    }
};