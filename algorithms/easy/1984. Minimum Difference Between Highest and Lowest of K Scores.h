// 1984. Minimum Difference Between Highest and Lowest of K Scores
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

// Runtime: 19 ms, faster than 70.91% of C++ online submissions for Minimum Difference Between Highest and Lowest of K Scores.
// Memory Usage: 13.7 MB, less than 24.17% of C++ online submissions for Minimum Difference Between Highest and Lowest of K Scores.
    
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int d = INT_MAX;
        for (int i = k - 1; i < nums.size(); ++i)
            d = min(d, nums[i] - nums[i - (k - 1)]);
        return d;
    }
};