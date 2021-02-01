// 1269. Number of Ways to Stay in the Same Place After Some Steps
// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

// Runtime: 208 ms, faster than 12.97% of C++ online submissions for Number of Ways to Stay in the Same Place After Some Steps.
// Memory Usage: 39 MB, less than 10.76% of C++ online submissions for Number of Ways to Stay in the Same Place After Some Steps.
    
class Solution {
    unordered_map<int, unordered_map<int, int64_t>> memo;
    int al;
    
    int64_t dp(int i, int steps) {
        if (i < 0 || i >= al || i > steps) return 0;
        if (i == steps) return 1;
        if (memo.count(i) && memo[i].count(steps)) return memo[i][steps];
        
        static const int64_t M = 1000000007;
        int64_t s = dp(i, steps - 1) % M;
        int64_t l = dp(i - 1, steps - 1) % M;
        int64_t r = dp(i + 1, steps - 1) % M;
        memo[i][steps] = (s + l + r) % M;
        return memo[i][steps];
    }
    
public:
    int numWays(int steps, int arrLen) {
        al = arrLen;
        return dp(0, steps);
    }
};

/*class Solution {
public:
    int numWays(int steps, int arrLen) {
        // left: '{', right: '}', stay: ' '
        // count('{') == count('}') -> [0, arrLen / 2]
        // count(' ') = arrLen - 2 * count('{')
        
        int ans = 1;
        int catalan_number = 1;
        for (int pairs = 1; pairs <= arrLen / 2; ++pairs) {
            int num_stay = arrLen - 2 * pairs;
            // ways(i pairs {}) * ways(insert num_stay spaces in 2 * i + 1 positions)
            ans = ans + catalan_number * insert_spaces(num_stay, 2 * i + 1);
            catalan_number = catalan_number * 2 * (2 * i + 1) / (i + 2);
        }
        return ans;
    }
    
    int insert_spaces(int spaces, int max_positions) {
        // todo
        return 1;
    }
};*/