#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CQueue {
    stack<int> input;
    stack<int> output;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        input.push(value);
    }
    
    int deleteHead() {
        if (input.size()==0)
            return -1;
        while(input.size()){
            output.push(input.top()); 
            input.pop();
        }
        int cur = output.top();
        output.pop();
        while(output.size()){
            input.push(output.top());
            output.pop();
        }
        return cur;
    }
};