#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;


/* class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
}; */

class MinStack {
private:
    stack<int> diff;
	int minValue;

public:
    void push(int x) {

	if (diff.empty()) {
			minValue = x;
			diff.push(0);
		} else {
			int compare = x - minValue;
			diff.push(compare);
			minValue = compare < 0 ? x : minValue;
		}
	}

	void pop() {
		int top = diff.top();
		minValue = top < 0 ? (minValue - top) : minValue;
		diff.pop();
	}

	int top() {
		int top = diff.top();
		return top > 0 ? top + minValue : minValue;
	}

	int getMin() {
		return minValue;
	}
}; 