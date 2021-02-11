#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SortedStack {
    stack<int> max_stack;   // min-bottom   max-top
    stack<int> min_stack;   // max-bottom   min-top  //main
public:
    SortedStack() {

    }
    
    void push(int val) {
        if (min_stack.size()==0)
            min_stack.push(val);
        else {
            while (min_stack.size() >0 && min_stack.top() < val){
                max_stack.push(min_stack.top());
                min_stack.pop();
            }
            min_stack.push(val);
            while (max_stack.size()){
                min_stack.push(max_stack.top());
                max_stack.pop();
            }
        }
    }
    
    void pop() {
        if (min_stack.size())
            min_stack.pop();
    }
    
    int peek() {
        if (min_stack.size())
            return min_stack.top();
        return -1;
    }
    
    bool isEmpty() {
        return min_stack.size()==0;
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */