// 16. 3Sum Closest

// Runtime: 500 ms, faster than 5.03% of C++ online submissions for 3Sum Closest.
// Memory Usage: 10 MB, less than 5.66% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int64_t ans = 2 * (int64_t)INT_MAX;
        find(nums, target, ans, 0, 3, 0);
        return ans;
    }
    
    void find(vector<int>& nums, int64_t target, int64_t& ans, int idx, int cnt, int64_t sum) {
        if (idx >= nums.size() || cnt <= 0) {
            if (cnt == 0) ans = abs(target - ans) <= abs(target - sum) ? ans : sum;
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            find(nums, target, ans, i + 1, cnt - 1, sum + nums[i]);
        }
    }
};