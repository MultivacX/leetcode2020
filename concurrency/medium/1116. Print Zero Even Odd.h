// 1116. Print Zero Even Odd
// https://leetcode.com/problems/print-zero-even-odd/

// Runtime: 16 ms, faster than 92.27% of C++ online submissions for Print Zero Even Odd.
// Memory Usage: 6.9 MB, less than 77.95% of C++ online submissions for Print Zero Even Odd.
    
class ZeroEvenOdd {
private:
    int n;
    atomic<int> i{1};
    atomic<int> s{0};
    mutex mtx;
    condition_variable cv;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            while (s != 0 && i <= n) cv.wait(lck);
            if (i > n) return;
            printNumber(0);
            s = i & 1 ? 1 : 2;
            lck.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            while (s != 2 && i <= n) cv.wait(lck);
            if (i > n) return;
            printNumber(i++);
            s = 0;
            lck.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            while (s != 1 && i <= n) cv.wait(lck);
            if (i > n) return;
            printNumber(i++);
            s = 0;
            lck.unlock();
            cv.notify_all();
        }
    }
};