// 754. Reach a Number

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reach a Number.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Reach a Number.

class Solution {
public:
    int reachNumber(int target) {
        // test();
        if (target == 0) return 0;
        
        int t = abs(target);
        // t <= n * (n + 1) / 2
        int n = ceil((1.0 + sqrt(1.0 + 8.0 * t)) / 2.0);
        int s = n * (n + 1) / 2;
        if (t == s) return n;
        
        if ((t & 1) == (s & 1)) {
            int pre_s = s - n;
            if (pre_s >= t && (t & 1) == (pre_s & 1))
                return n - 1;
            return n;
        }
        
        int pre_s = s - n;
        if (pre_s >= t && (t & 1) == (pre_s & 1))
            return n - 1;
        int suf_s = s + n + 1;
        if ((t & 1) == (suf_s & 1))
            return n + 1;
        
        return n;
    }
    
    // void test() {
    //     for (int t = 90; t <= 101; ++t) {
    //         int n = ceil((1.0 + sqrt(1.0 + 8.0 * t)) / 2.0);
    //         int sum = n * (n + 1) / 2;
    //         printf("t:%d, n:%d, sum:%d\n", t, n, sum);
    //     }
    // }
};