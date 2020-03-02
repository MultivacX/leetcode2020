// 232. Implement Queue using Stacks

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (first.empty()) {
            while (!last.empty()) {
                first.push(last.top());
                last.pop();
            }
        }
        first.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ans = peek();
        last.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        if (last.empty()) {
            while (!first.empty()) {
                last.push(first.top());
                first.pop();
            }
        }
        return last.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return first.empty() && last.empty();
    }
    
    stack<int> first; // peek is at stack bottom
    stack<int> last; // peek is at stack top
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */