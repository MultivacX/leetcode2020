// 641. Design Circular Deque

// Runtime: 36 ms, faster than 81.82% of C++ online submissions for Design Circular Deque.
// Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Design Circular Deque.

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : _k(k), _c(0), _v(k, 0), _b(0), _e(0) {
        
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        ++_c;
        --_b;
        _b = (_k + _b) % _k;
        _v[_b] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        ++_c;
        ++_e;
        _e = _e % _k;
        _v[(_k + _e - 1) % _k] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        --_c;
        ++_b;
        _b = _b % _k;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        --_c;
        --_e;
        _e = (_k + _e) % _k;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : _v[(_k + _b) % _k];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : _v[(_k + _e - 1) % _k];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _c == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _c == _k;
    }
    
    const int _k;
    int _c;
    vector<int> _v;
    int _b;
    int _e;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */