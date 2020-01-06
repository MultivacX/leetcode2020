// 1137. N-th Tribonacci Number

// Runtime: 4 ms, faster than 49.58% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for N-th Tribonacci Number.

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};