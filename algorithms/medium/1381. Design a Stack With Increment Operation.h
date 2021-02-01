// 1381. Design a Stack With Increment Operation

// Runtime: 40 ms, faster than 83.97% of C++ online submissions for Design a Stack With Increment Operation.
// Memory Usage: 19.4 MB, less than 100.00% of C++ online submissions for Design a Stack With Increment Operation.

class CustomStack {
public:
    CustomStack(int maxSize) : capacity(maxSize), size(0), v(maxSize, 0) {
        
    }
    
    void push(int x) {
        if (capacity == size) return;
        v[size++] = x;
    }
    
    int pop() {
        if (0 == size) return -1;
        return v[--size];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, size); ++i) 
            v[i] += val;
    }
    
    const int capacity;
    int size;
    vector<int> v;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */