// 1114. Print in Order
// https://leetcode.com/problems/print-in-order/

// Runtime: 24 ms, faster than 93.96% of C++ online submissions for Print in Order.
// Memory Usage: 7.1 MB, less than 89.74% of C++ online submissions for Print in Order.
    
class Foo {
    // mutex mtx1;
    mutex mtx2;
    mutex mtx3;
    
public:
    Foo() {
        mtx2.try_lock();
        mtx3.try_lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx2.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> lock(mtx2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx3.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard<mutex> lock(mtx3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};