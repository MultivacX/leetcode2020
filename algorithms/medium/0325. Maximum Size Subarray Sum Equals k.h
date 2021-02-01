// 325. Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

// Runtime: 56 ms, faster than 92.62% of C++ online submissions for Maximum Size Subarray Sum Equals k.
// Memory Usage: 18 MB, less than 27.24% of C++ online submissions for Maximum Size Subarray Sum Equals k.
    
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefix{{0, -1}};
        int len = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int diff = sum - k;
            // cout << i << ": " << sum << ", " << diff << endl;
            if (prefix.count(diff)) 
                len = max(len, i - prefix[diff]);
            if (prefix.count(sum) == 0)
                prefix.insert({sum, i});
        }
        return len;
    }
};