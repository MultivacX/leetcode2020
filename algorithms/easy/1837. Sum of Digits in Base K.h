// 1837. Sum of Digits in Base K
// https://leetcode.com/problems/sum-of-digits-in-base-k/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Digits in Base K.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Sum of Digits in Base K.
    
class Solution {
public:
    int sumBase(int n, int k) {
        int m = 0;
        while (n) {
            m += n % k;
            n /= k;
        }
        return m;
    }
};