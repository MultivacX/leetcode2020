// 155. Min Stack

// Runtime: 48 ms, faster than 15.18% of C++ online submissions for Min Stack.
// Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Min Stack.

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        ++m[x];
    }
    
    void pop() {
        if (--m[s.top()] == 0) m.erase(s.top());
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
    
    stack<int> s;
    map<int, int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */