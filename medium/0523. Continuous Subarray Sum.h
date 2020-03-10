// 523. Continuous Subarray Sum

// Runtime: 28 ms, faster than 81.52% of C++ online submissions for Continuous Subarray Sum.
// Memory Usage: 10.9 MB, less than 90.00% of C++ online submissions for Continuous Subarray Sum.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // nums[i] >= 0
        // sum[j, i] == n * k, j < i
        // 0 + 0 == 0 * k
        const int N = nums.size();
        if (N < 2) return false;
        for (int i = 0; i < N - 1; ++i)
                if (nums[i] == 0 && nums[i + 1] == 0)
                    return true;
        if (k == 0) return false;
        
        vector<int64_t> sums(N, 0);
        sums[0] = nums[0];
        
        unordered_map<int, int> remainders;
        remainders.insert({sums[0] % k, 0});
        
        for (int i = 1; i < N; ++i) {
            sums[i] = sums[i - 1] + nums[i];
            int r = sums[i] % k;
            if (r == 0) return true;
            if (nums[i] == 0) continue;
            
            if (remainders.count(r)) {
                if (remainders[r] < i - 1) return true;
            } else {
                remainders.insert({r, i});
            }
        }
        return false;
    }
};