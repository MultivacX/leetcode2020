// 1117. Building H2O
// https://leetcode.com/problems/building-h2o/

// Runtime: 204 ms, faster than 44.42% of C++ online submissions for Building H2O.
// Memory Usage: 8.8 MB, less than 77.68% of C++ online submissions for Building H2O.
    
class H2O {
    atomic<int> H{0};
    mutex mtx;
    condition_variable cv;
    
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        while (H == 2) cv.wait(lck);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        H += 1;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        while (H != 2) cv.wait(lck);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        H = 0;
        cv.notify_all();
    }
};