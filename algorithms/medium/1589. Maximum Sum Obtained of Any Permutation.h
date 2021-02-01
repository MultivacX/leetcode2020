// 1589. Maximum Sum Obtained of Any Permutation
// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/submissions/

// Runtime: 892 ms, faster than 61.98% of C++ online submissions for Maximum Sum Obtained of Any Permutation.
// Memory Usage: 120.7 MB, less than 15.95% of C++ online submissions for Maximum Sum Obtained of Any Permutation.

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int N = nums.size();
        vector<int> count(N, 0);
        for (const auto& req : requests) {
            ++count[req[0]];
            if (req[1] + 1 < N) 
                --count[req[1] + 1];
        }
        for (int i = 1; i < N; ++i) {
            count[i] += count[i - 1];
        }
        sort(begin(count), end(count));
        sort(begin(nums), end(nums));
        int64_t ans = 0;
        for (int i = N - 1; i >= 0 && count[i] > 0; --i) {
            ans = (ans + (int64_t)count[i] * (int64_t)nums[i] % 1000000007) % 1000000007;
        }
        return ans;
    }
};