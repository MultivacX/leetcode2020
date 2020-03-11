// 462. Minimum Moves to Equal Array Elements II

// Runtime: 16 ms, faster than 83.80% of C++ online submissions for Minimum Moves to Equal Array Elements II.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Minimum Moves to Equal Array Elements II.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        std::sort(std::begin(nums), std::end(nums));
        if (nums[0] == nums[n - 1]) return 0;
        int64_t mid_v = n & 1 ? nums[n >> 1] : ((int64_t)nums[(n >> 1) - 1] + (int64_t)nums[n >> 1]) >> 1; 
        int ans = 0;
        std::for_each(std::begin(nums), std::end(nums), [&](const int& num){ ans += std::labs(mid_v - (int64_t)num); });
        return ans;
    }
};