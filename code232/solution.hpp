#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> store;
    stack<int> out;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        store.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (store.size())
        {
            out.push(store.top());
            store.pop();
        }
        int cur = out.top();
        out.pop();
        while(out.size()){
            store.push(out.top());
            out.pop();
        }
        return cur;
    }
    
    /** Get the front element. */
    int peek() {
        while (store.size())
        {
            out.push(store.top());
            store.pop();
        }
        int cur = out.top();
        while(out.size()){
            store.push(out.top());
            out.pop();
        }
        return cur;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return store.empty();
    }
};