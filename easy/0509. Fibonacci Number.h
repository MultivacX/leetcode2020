// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6.3 MB, less than 59.97% of C++ online submissions for Fibonacci Number.
    
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int a = 0, b = 1;
        for (int i = 2; i <= N; ++i) {
            a = a + b;
            swap(a, b);
        }
        return b;
    }
};