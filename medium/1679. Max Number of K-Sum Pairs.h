// 1679. Max Number of K-Sum Pairs
// https://leetcode.com/problems/max-number-of-k-sum-pairs/

// Runtime: 500 ms, faster than 33.32% of C++ online submissions for Max Number of K-Sum Pairs.
// Memory Usage: 58.6 MB, less than 86.71% of C++ online submissions for Max Number of K-Sum Pairs.
    
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = 0, i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) ++i, --j, ++ans;
            else if (sum > k) --j;
            else ++i;
        }
        return ans;
    }
};