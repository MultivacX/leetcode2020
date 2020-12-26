// 276. Paint Fence
// https://leetcode.com/problems/paint-fence/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Paint Fence.
// Memory Usage: 6.4 MB, less than 29.88% of C++ online submissions for Paint Fence.
    
class Solution {
    unordered_map<int, int> memo;
    
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * (k - 1) + k;
        if (k == 1) return 0;
        
        if (memo.count(n)) return memo[n];
        int ans = (k - 1) * (numWays(n - 1, k) + numWays(n - 2, k));
        memo[n] = ans;
        return ans;
    }
};