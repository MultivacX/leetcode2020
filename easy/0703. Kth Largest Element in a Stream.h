// 703. Kth Largest Element in a Stream

// Runtime: 52 ms, faster than 53.67% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 18.5 MB, less than 100.00% of C++ online submissions for Kth Largest Element in a Stream.

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : _k(k) {
        for (int num : nums) {
            _q.push(num);
            while (_q.size() > _k) 
                _q.pop();
        }
    }
    
    int add(int val) {
        _q.push(val);
        while (_q.size() > _k) 
            _q.pop();
        return _q.top();
    }
    
    int _k;
    priority_queue<int, vector<int>, greater<int>> _q;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */