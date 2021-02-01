// 96. Unique Binary Search Trees

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
// Memory Usage: 8.8 MB, less than 6.82% of C++ online submissions for Unique Binary Search Trees.

class Solution {
public:
    int numTrees(int n) {
        static unordered_map<int, int> m;
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (m.count(n)) return m[n];
        
        int ans = numTrees(n - 1) * 2;
        // printf("%d -- L:%d, R:%d\n", n, n - 1, 0);
        // printf("%d -- L:%d, R:%d\n", n, 0, n - 1);
        for (int i = 1; i <= n - 2; ++i) {
            ans += numTrees(i) * numTrees(n - i - 1);
            // printf("%d -- L:%d, R:%d\n", n, i, n - i - 1);
        }
         m[n] = ans;
        return ans;
    }
};