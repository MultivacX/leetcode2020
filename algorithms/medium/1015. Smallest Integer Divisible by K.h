// 1015. Smallest Integer Divisible by K

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Smallest Integer Divisible by K.

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if ((K & 1) == 0) return -1;
        
        int L = 1;
        int N = 1;
        while (N < K) ++L, N = N * 10 + 1;
        
        int M = N % K;
        int m = M;
        while (M != 0) {
            M = (M * 10 + 1) % K;
            if (M == m) return -1;
            ++L;
        }
        
        return L;
    }
};