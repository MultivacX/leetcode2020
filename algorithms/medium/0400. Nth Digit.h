// 400. Nth Digit

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nth Digit.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Nth Digit.

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        
        uint64_t N = n;
        uint64_t k = 9;
        uint64_t len = 1;
        uint64_t pre = 0;
        uint64_t cnt = 9;
        while (true) {
            if (N <= cnt) {
                N = N - pre - 1;
                int num = pow(10, len - 1) + N / len;
                string s(to_string(num));
                // cout << s << endl;
                return s[N % len] - '0';
            }
            k *= 10;
            ++len;
            pre = cnt;
            cnt += k * len;
        }
        return N;
    }
};