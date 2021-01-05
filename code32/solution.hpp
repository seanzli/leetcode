#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
 /*    int char2int(char i){
        switch (i){
            case '(' :  return -1;
            case ')' :  return 1;
        }
        return 0;
    }
    int longestValidParentheses(string s) {
        stack<int> parenthes;
        int count = 0, sum1=0, sum2=0;
        //forward
        for (int i = 0; i < s.size(); i++)
        {
            if (char2int(s[i])<0)
            {
                parenthes.push(-1);
            }
            else
            {
                if (parenthes.size()>0)
                {
                    count+=2;
                    parenthes.pop();
                    if (parenthes.empty())
                        sum1 = max(sum1, count);
                }
                else
                {
                    while(!parenthes.empty())
                        parenthes.pop();
                    count = 0;
                }
            }
        }
        count=0;
        while(!parenthes.empty())
            parenthes.pop();
        //backward
        for (int i = s.size()-1; i >=0; i--)
        {
            if (char2int(s[i])>0)
            {
                parenthes.push(1);
            }
            else
            {
                if (parenthes.size()>0)
                {
                    count+=2;
                    parenthes.pop();
                    if (parenthes.empty())
                        sum2 = max(sum2, count);
                }
                else
                {
                    while(!parenthes.empty())
                        parenthes.pop();
                    count = 0;
                }
            }
        }
        return max(sum1,sum2);
    } */
    int longestValidParentheses(string s) {
        int *lists = new int[s.size()]();
        stack<pair<char, int>> stacks;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stacks.push(pair<char, int>('(',i));
            else
            {
                if (!stacks.empty())
                {
                    lists[stacks.top().second]=1;
                    lists[i]=1;
                    stacks.pop();
                }
            }
        }
        int most = 0, cur=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (lists[i]==1)
                cur++;
            else
            {
                most = max(most, cur);
                cur = 0;
            }
        }
        return max(most, cur);
    }
};