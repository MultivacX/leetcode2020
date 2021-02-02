// 1115. Print FooBar Alternately
// https://leetcode.com/problems/print-foobar-alternately/

// Runtime: 28 ms, faster than 91.84% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 8.1 MB, less than 92.09% of C++ online submissions for Print FooBar Alternately.
    
class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int j = 0;
    
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            if (j == 1) cv.wait(lck);
        	printFoo();
            j = 1;
            lck.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            if (j == 0) cv.wait(lck);
        	printBar();
            j = 0;
            lck.unlock();
            cv.notify_all();
        }
    }
};