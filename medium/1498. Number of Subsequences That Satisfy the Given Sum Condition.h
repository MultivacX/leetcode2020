// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// Runtime: 296 ms, faster than 96.12% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
// Memory Usage: 50 MB, less than 12.03% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        const int N = nums.size();
        vector<int> pows(N, 1);
        for (int i = 1 ; i < N; ++i)
            pows[i] = pows[i - 1] * 2 % 1000000007;
        
        int ans = 0;
        int i = 0;
        int j = N - 1;
        while (i <= j) {
            if (nums[i] + nums[j] > target) {
                --j;
                continue;
            }
            int n = j - i;
            ans = (ans + pows[n]) % 1000000007;
            ++i;
        }
        return ans;
    }
};


// Runtime: 360 ms, faster than 46.62% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
// Memory Usage: 50.1 MB, less than 12.03% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        const int N = nums.size();
        vector<int> pows(N, 1);
        for (int i = 1 ; i < N; ++i)
            pows[i] = pows[i - 1] * 2 % 1000000007;
        
        int ans = 0;
        for (int i = 0; i < N && nums[i] * 2 <= target; ++i) {
            int n = upper_bound(begin(nums), end(nums), target - nums[i]) - begin(nums) - 1 - i;
            ans = (ans + pows[n]) % 1000000007;
        }
        return ans;
    }
};