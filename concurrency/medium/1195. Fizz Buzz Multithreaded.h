// 1195. Fizz Buzz Multithreaded
// https://leetcode.com/problems/fizz-buzz-multithreaded/

// Runtime: 8 ms, faster than 95.79% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 6.8 MB, less than 67.72% of C++ online submissions for Fizz Buzz Multithreaded.
    
class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lck(mtx);
        while (i <= n) {
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
                ++i;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lck(mtx);
        while (i <= n) {
            if (i % 3 != 0 && i % 5 == 0) {
                printBuzz();
                ++i;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lck(mtx);
        while (i <= n) {
            if (i % 15 == 0) {
                printFizzBuzz();
                ++i;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mtx);
        while (i <= n) {
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
                ++i;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }
};