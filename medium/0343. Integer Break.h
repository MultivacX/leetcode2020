// 343. Integer Break

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Integer Break.

class Solution {
public:
    int integerBreak(int n) {
        // cout << n << "->";
        static unordered_map<int, int> m{{1, 1}, {2, 1}, {3, 2}};
        if (m.count(n)) return m[n];
        int ans = 0;
        for (int i = 2; i <= (n >> 1) && n - i >= 1; ++i)
            ans = max(ans, max(i, integerBreak(i)) * max(n - i, integerBreak(n - i)));
        m[n] = ans;
        return m[n];
    }
};