// 716. Max Stack
// https://leetcode.com/problems/max-stack/

// Runtime: 116 ms, faster than 53.91% of C++ online submissions for Max Stack.
// Memory Usage: 39 MB, less than 58.36% of C++ online submissions for Max Stack.
    
class MaxStack {
    list<int> stk;
    map<int, vector<list<int>::iterator>> m;
    
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        m[x].push_back(stk.insert(stk.end(), x));
    }
    
    int pop() {
        int x = stk.back();
        stk.pop_back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }
    
    int top() {
        return stk.back();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        auto it = m.rbegin()->second.back();
        int x = *it;
        stk.erase(it);
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */