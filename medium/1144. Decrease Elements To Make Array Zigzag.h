// 1144. Decrease Elements To Make Array Zigzag
// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

// misunderstand
// 20 / 31 test cases passed.
// Status: Wrong Answer
/*class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return 0;
        
        // a[2k-1] < a[2k] > a[2k+1]
        vector<int> dp(N, 0);
        dp[0] = nums[0] > nums[1] ? 0 : nums[1] + 1 - nums[0];
        for (int i = 1; i < N; ++i) {
            int l = nums[i - 1];
            int m = nums[i];
            if (i % 2 == 0) {
                int r = i == N - 1 ? -1 : nums[i + 1];
                int maxVal = max(l, r);
                int moves = m > maxVal ? 0 : maxVal + 1 - m;
                dp[i] = moves + (i > 1 ? dp[i - 2] : 0);
            } else {
                int r = i == N - 1 ? 1001 : nums[i + 1];
                int minVal = min(l, r);
                int moves = m < minVal ? 0 : m + 1 - minVal;
                dp[i] = moves + (i > 1 ? dp[i - 2] : 0);
            }
        }
        
        int ans = min(dp[N - 2], dp[N - 1]);
        
        // a[2k-1] > a[2k] < a[2k+1]
        fill(begin(dp), end(dp), 0);
        dp[0] = nums[0] < nums[1] ? 0 : nums[0] + 1 - nums[1];
        for (int i = 1; i < N; ++i) {
            int l = nums[i - 1];
            int m = nums[i];
            if (i % 2 == 0) {
                int r = i == N - 1 ? 1001 : nums[i + 1];
                int minVal = min(l, r);
                int moves = m < minVal ? 0 : m + 1 - minVal;
                dp[i] = moves + (i > 1 ? dp[i - 2] : 0);
            } else {
                int r = i == N - 1 ? -1 : nums[i + 1];
                int maxVal = max(l, r);
                int moves = m > maxVal ? 0 : maxVal + 1 - m;
                dp[i] = moves + (i > 1 ? dp[i - 2] : 0);
            }
        }
        
        return min(ans, min(dp[N - 2], dp[N - 1]));
    }
};*/
