// 1188. Design Bounded Blocking Queue
// https://leetcode.com/problems/design-bounded-blocking-queue/

// Runtime: 104 ms, faster than 51.76% of C++ online submissions for Design Bounded Blocking Queue.
// Memory Usage: 8.7 MB, less than 72.46% of C++ online submissions for Design Bounded Blocking Queue.
    
class BoundedBlockingQueue {
    const int n;
    atomic<int> s{0};
    queue<int> q;
    mutex mtx;
    condition_variable cv;
    
public:
    BoundedBlockingQueue(int capacity) : n(capacity) {
        
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this](){ return this->s < n; });
        q.push(element);
        s += 1;
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this](){ return this->s > 0; });
        s -= 1;
        int ans = q.front();
        q.pop();
        cv.notify_all();
        return ans;
    }
    
    int size() {
        return s;
    }
};