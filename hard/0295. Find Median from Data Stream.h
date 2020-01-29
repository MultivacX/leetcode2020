// 295. Find Median from Data Stream

// Runtime: 176 ms, faster than 37.14% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 42.5 MB, less than 95.65% of C++ online submissions for Find Median from Data Stream.

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        l.push(num);
        while (!l.empty() && !r.empty() && l.top() > r.top()) {
            int i = l.top();
            int j = r.top();
            l.pop();
            r.pop();
            l.push(j);
            r.push(i);
        }
    }
    
    double findMedian() {
        while (r.size() + 1 < l.size()) {
            r.push(l.top());
            l.pop();
        }
        auto size = l.size() + r.size();
        if (size == 0) return 0;
        else if (size % 2) return l.top();
        else return (l.top() + r.top()) / 2.0;
    }
    
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */