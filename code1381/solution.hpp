#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class CustomStack {
    stack<int> in;
    stack<int> out;
    int max_length = 0;
public:
    CustomStack(int maxSize) {
        max_length = maxSize;
    }
    
    void push(int x) {
        if (in.size()<max_length)
            in.push(x);
    }
    
    int pop() {
        if (in.size()==0)
            return -1;
        int cur = in.top();
        in.pop();
        return cur;
    }
    
    void increment(int k, int val) {
        while (in.size()){
            out.push(in.top());
            in.pop();
        }

        while(out.size()){
            if (in.size()<k)
                in.push(out.top()+val);
            else
                in.push(out.top());
            out.pop();
        }
    }
};