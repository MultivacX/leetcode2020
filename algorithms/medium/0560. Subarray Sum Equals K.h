// 560. Subarray Sum Equals K

// Runtime: 32 ms, faster than 90.95% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 13.5 MB, less than 72.00% of C++ online submissions for Subarray Sum Equals K.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> sums; // {sum, cnt}
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) ++cnt;
            if (sums.count(sum - k)) cnt += sums[sum - k];
            ++sums[sum];
        }
        return cnt;
    }
};