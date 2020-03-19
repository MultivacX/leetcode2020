// 622. Design Circular Queue

// Runtime: 32 ms, faster than 83.59% of C++ online submissions for Design Circular Queue.
// Memory Usage: 15.4 MB, less than 100.00% of C++ online submissions for Design Circular Queue.

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : capacity(k), size(0), begin(0), end(0), v(k, 0) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        ++size;
        v[end] = value;
        end = (end + 1) % capacity;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        --size;
        begin = (begin + 1) % capacity;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : v[begin];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : v[(capacity + end - 1) % capacity];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return 0 == size;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capacity == size;
    }
    
    const int capacity;
    int size;
    int begin;
    int end;
    vector<int> v;    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */