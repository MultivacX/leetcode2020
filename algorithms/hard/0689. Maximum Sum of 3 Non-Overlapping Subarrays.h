// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

// Runtime: 60 ms, faster than 51.78% of C++ online submissions for Maximum Sum of 3 Non-Overlapping Subarrays.
// Memory Usage: 24.1 MB, less than 5.06% of C++ online submissions for Maximum Sum of 3 Non-Overlapping Subarrays.

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        const int M = N - k + 1;
        vector<int> sums(M);
        sums[0] = accumulate(begin(nums), begin(nums) + k, 0);
        for (int i = 1; i < M; ++i)
            sums[i] = sums[i - 1] - nums[i - 1] + nums[i + k - 1];

        // sums[i] = nums[i] + ... + nums[i + k - 1]
        // ans = sums[a] + sums[b] + sums[c], a + k - 1 < b, b + k - 1 < c

        vector<int> maxSumIdx1(M);
        for (int c = M - 1; c >= 2 * k; --c) {
            if (c == M - 1) maxSumIdx1[c] = c;
            else {
                int i = maxSumIdx1[c + 1];
                if (sums[c] < sums[i]) maxSumIdx1[c] = i;
                else maxSumIdx1[c] = c;
            }
        }
            
        vector<vector<int>> maxSumIdx2(M);
        for (int b = M - 1 - k; b >= k; --b) {
            int c = b + k;
            if (b == M - 1 - k) maxSumIdx2[b] = {b, maxSumIdx1[c]}; 
            else {
                int pre = sums[maxSumIdx2[b + 1][0]] + sums[maxSumIdx2[b + 1][1]];
                int cur = sums[b] + sums[maxSumIdx1[c]];
                if (cur < pre) maxSumIdx2[b] = maxSumIdx2[b + 1];
                else maxSumIdx2[b] = {b, maxSumIdx1[c]}; 
            }
        }

        vector<int> ans;
        int pre = 0;
        for (int a = 0; a <= M - 1 - 2 * k; ++a) {
            int b = maxSumIdx2[a + k][0];
            int c = maxSumIdx2[a + k][1];
            int cur = sums[a] + sums[b] + sums[c];
            if (pre < cur) ans = {a, b, c}, pre = cur;
        }
        return ans;
    }
};