// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/

// Runtime: 4 ms, faster than 75.77% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 7.7 MB, less than 8.52% of C++ online submissions for Split Array Largest Sum.
    
class Solution {
    bool check(const vector<int>& nums, const int m, const int64_t targetMaxSum) {
        const int N = nums.size();
        int64_t curSum = nums[0];
        int count = 1;
        for (int i = 1; i < N; ++i) {
            curSum += (int64_t)nums[i];
            if (curSum > targetMaxSum) {
                // targetMaxSum is a small choice
                // time to check a big sum
                if (++count > m) return false;
                curSum = nums[i];
            }
        }
        // targetMaxSum is a big/right choice
        // time to check a small sum or return anwser
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        int64_t max_element = 0;
        int64_t sum = 0;
        for (int i = 0; i < N; ++i) {
            max_element = max(max_element, (int64_t)nums[i]);
            sum += (int64_t)nums[i];
        }
        if (N == m) return max_element;
        if (1 == m) return sum;
        
        // search space [max_element, sum + 1)
        int64_t l = max_element;
        int64_t r = sum + 1;
        while (l < r) {
            int64_t targetMaxSum = (l + r) / 2;
            if (check(nums, m, targetMaxSum)) r = targetMaxSum; 
            else l = targetMaxSum + 1;
                
        }
        return l;
    }
};

// Runtime: 492 ms, faster than 6.00% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 7.9 MB, less than 14.90% of C++ online submissions for Split Array Largest Sum.

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        vector<int64_t> sums(N, 0);
        for (int64_t i = 0, sum = 0; i < N; ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
        
        vector<vector<int64_t>> dp(N, vector<int64_t>(m + 1, INT_MAX));
        for (int i = 0; i < N; ++i) {
            dp[i][1] = sums[i];

            const int M = min(i + 1, m);
            for (int j = 2; j <= M; ++j) {
                // nums[0, k]_[j-1]parts & [k+1, i]_[1]part
                for (int k = j - 2; k <= i - 1; ++k) {
                    int64_t val = max(dp[k][j - 1], sums[i] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[N - 1][m];
    }
};


// TLE
// 28 / 28 test cases passed, but took too long.
class Solution {
    int dp(const vector<int>& prefix_sums, int i, int j, int m, vector<vector<vector<int>>>& memo) {
        int left = i == 0 ? 0 : prefix_sums[i - 1];
        if (m == 1) return prefix_sums[j] - left;
        if (memo[i][j][m] != -1) return memo[i][j][m];
        
        int ans = INT_MAX;
        for (int k = i; k <= j - m + 1; ++k) 
            ans = min(ans, max(prefix_sums[k] - left, dp(prefix_sums, k + 1, j, m - 1, memo)));
        return memo[i][j][m] = ans;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        vector<int> prefix_sums(n);
        prefix_sums[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix_sums[i] = prefix_sums[i - 1] + nums[i];
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(m + 1, -1)));
        return dp(prefix_sums, 0, n - 1, m, memo);
    }
};


class Solution {
    bool check(const vector<int>& nums, int m, int targetSum) {
        int curParts = 0;
        int curSum = 0;
        for (int i : nums) {
            curSum += i;
            if (curSum == targetSum) {
                if (++curParts > m)
                    return false;
                curSum = 0;
            } else if (curSum > targetSum) {
                if (++curParts >= m)
                    return false;
                curSum = i;
            }
        }
        if (curSum > 0 && ++curParts > m)
            return false;
        return true;
    }

public:
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        int l = 0, r = 1;
        for (int i : nums) {
            l = max(l, i);
            r += i;
        }
        
        while (l < r) {
            int t = l + (r - l) / 2;
            if (check(nums, m, t)) r = t;
            else l = t + 1;
        }
        return l;
    }
};