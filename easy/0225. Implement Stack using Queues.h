// 225. Implement Stack using Queues

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Implement Stack using Queues.

class MyStack {
    queue<int> p;
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (!p.empty()) p.push(x);
        else q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (p.empty()) swap(p, q);
        while (p.size() > 1) {
            q.push(p.front());
            p.pop();
        }
        int ans = p.front();
        p.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        if (!p.empty()) return p.back();
        else return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return p.empty() && q.empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */