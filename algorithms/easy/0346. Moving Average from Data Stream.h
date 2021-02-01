// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

// Runtime: 32 ms, faster than 47.49% of C++ online submissions for Moving Average from Data Stream.
// Memory Usage: 14.2 MB, less than 83.23% of C++ online submissions for Moving Average from Data Stream.
    
class MovingAverage {
    queue<int> q;
    double sum;
    int s;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sum(0), s(size) {
        
    }
    
    double next(int val) {
        q.push(val);
        int v = 0;
        if (q.size() > s) { 
            v = q.front(); 
            q.pop(); 
        }
        sum += val - v;
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */