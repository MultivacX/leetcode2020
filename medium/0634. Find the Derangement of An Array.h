// 634. Find the Derangement of An Array
// https://leetcode.com/problems/find-the-derangement-of-an-array/submissions/

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Find the Derangement of An Array.
// Memory Usage: 6.2 MB, less than 91.30% of C++ online submissions for Find the Derangement of An Array.
    
class Solution {
public:
    int findDerangement(int n) {
        int64_t a = 1;
        int64_t b = 0;
        for (int i = 2; i <= n; ++i) {
            int64_t c = (i - 1) * (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return b;
    }
};

// Runtime: 28 ms, faster than 26.09% of C++ online submissions for Find the Derangement of An Array.
// Memory Usage: 83.4 MB, less than 8.70% of C++ online submissions for Find the Derangement of An Array.
    
class Solution {
    int64_t h(int64_t n, vector<int64_t>& memo) {
        if (memo[n] >= 0) return memo[n];
        // h(n - 1, memo) : nums[i] in position 0 & 1 can NOT appear in position i
        // h(n - 2, memo) : swap(0, i)
        int64_t ans = (n - 1) * (h(n - 1, memo) + h(n - 2, memo)) % 1000000007;
        memo[n] = ans;
        return ans;
    }
    
public:
    int findDerangement(int n) {
        vector<int64_t> memo(n + 1, -1);
        memo[0] = 1;
        memo[1] = 0;
        return h(n, memo);
    }
};