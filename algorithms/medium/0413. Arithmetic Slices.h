// 413. Arithmetic Slices

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arithmetic Slices.
// Memory Usage: 8.7 MB, less than 93.75% of C++ online submissions for Arithmetic Slices.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int n = A.size();
        if (n < 3) return 0;
        
        auto f = [](int l, int r) -> int {
            // printf("    [%d, %d]\n", l, r);
            if (r - l >= 2) {
                int k = r - l - 1;
                return (k + 1) * k / 2;
            }
            return 0;
        };
        
        int ans = 0;
        int idx = 0;
        int diff = A[1] - A[0];
        for (int i = 2; i < n; ++i) {
            int d = A[i] - A[i - 1];
            if (diff != d) {
                // printf("! %d %d\n", diff, d);
                ans += f(idx, i - 1);
                idx = i - 1;
                diff = d;
            } else if (i == n - 1) {
                // printf("  %d %d\n", diff, d);
                ans += f(idx, i);
            }
        }
        return ans;
    }
};