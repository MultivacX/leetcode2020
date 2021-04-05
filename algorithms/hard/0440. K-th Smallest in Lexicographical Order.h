// 440. K-th Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for K-th Smallest in Lexicographical Order.
// Memory Usage: 5.8 MB, less than 62.50% of C++ online submissions for K-th Smallest in Lexicographical Order.
    
class Solution {
    int count(int64_t prefix, const int64_t n) {
        int64_t cnt = 0, r = prefix + 1;
        while (prefix <= n) {
            r = min(r, n + 1);
            cnt += r - prefix;
            // move to next level
            prefix *= 10;
            r *= 10;
        }
        return cnt;
    }
    
public:
    int findKthNumber(int n, int k) {
        int prefix = 1, ptr = 1;
        while (ptr < k) {
            int cnt = count(prefix, n);
            if (ptr + cnt > k) {
                // move to most-left child
                prefix *= 10;
                ptr += 1;
            } else {
                // move to right siblin
                prefix += 1;
                ptr += cnt;
            }
        }
        return prefix;
    }
};