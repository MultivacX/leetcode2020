// 1670. Design Front Middle Back Queue
// https://leetcode.com/problems/design-front-middle-back-queue/

// Runtime: 56 ms, faster than 74.16% of C++ online submissions for Design Front Middle Back Queue.
// Memory Usage: 20.7 MB, less than 51.06% of C++ online submissions for Design Front Middle Back Queue.
    
class FrontMiddleBackQueue {
    list<int> nums;
    list<int>::iterator middle;
    
public:
    FrontMiddleBackQueue() {
        middle = nums.end();
    }
    
    void pushFront(int val) {
        nums.push_front(val);
        if (nums.size() == 1) middle = nums.begin();
        else if (nums.size() & 1) --middle;
    }
    
    void pushMiddle(int val) {
        nums.insert(middle, val);
        if (nums.size() & 1) --middle;
    }
    
    void pushBack(int val) {
        nums.push_back(val);
        if (nums.size() == 1) middle = nums.begin();
        else if (nums.size() % 2 == 0) ++middle;
    }
    
    int popFront() {
        if (nums.empty()) return -1;
        
        int val = nums.front();
        nums.pop_front();
        if (nums.empty()) { middle = nums.end(); return val; }
        if (nums.size() == 1) middle = nums.begin();
        else if (nums.size() % 2 == 0) ++middle;
        return val;
    }
    
    int popMiddle() {
        if (nums.empty()) return -1;
        
        int val = *middle;
        auto it = middle;
        if (nums.size() & 1) ++middle;
        else val = *(--it);
        nums.erase(it);
        return val;
    }
    
    int popBack() {
        if (nums.empty()) return -1;
        
        int val = nums.back();
        nums.pop_back();
        if (nums.empty()) { middle = nums.end(); return val; }
        if (nums.size() == 1) middle = nums.begin();
        else if (nums.size() & 1) --middle;
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */