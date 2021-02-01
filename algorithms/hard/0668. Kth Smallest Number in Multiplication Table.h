// 668. Kth Smallest Number in Multiplication Table

// Runtime: 24 ms, faster than 75.06% of C++ online submissions for Kth Smallest Number in Multiplication Table.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Kth Smallest Number in Multiplication Table.

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1 * 1;
        int hi = m * n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int rows = mid / n;
            int val = rows * n;
            int cnt = rows * n;
            for (int i = rows + 1; i <= m && mid >= i; ++i) {
                // i * j <= mid
                int j = mid / i;                
                val = max(val, i * j);
                cnt += j;
            }
            if (cnt == k) return val;
            if (cnt < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};