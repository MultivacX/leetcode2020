// 895. Maximum Frequency Stack

// Runtime: 388 ms, faster than 13.04% of C++ online submissions for Maximum Frequency Stack.
// Memory Usage: 72.4 MB, less than 91.67% of C++ online submissions for Maximum Frequency Stack.

class FreqStack {
public:
    struct Node {
        Node(int v, int f) : val(v), freq(f) {}
        int val;
        int freq;
    };
    
    int max_freq{0};
    unordered_map<int, vector<Node*>> vals; // {val, {nodes}}
    unordered_map<int, vector<Node*>> freqs; // {freq, {nodes}}
    
    FreqStack() {
        
    }
    
    void push(int x) {
        int freq = vals[x].size();
        auto node = new Node(x, freq);
        
        max_freq = max(max_freq, freq);
        vals[x].push_back(node);
        freqs[freq].push_back(node);
    }
    
    int pop() {
        auto node = freqs[max_freq].back();
        freqs[max_freq].pop_back();
        if (freqs[max_freq].empty()) --max_freq;
        vals[node->val].pop_back();
        int val = node->val;
        delete node;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */