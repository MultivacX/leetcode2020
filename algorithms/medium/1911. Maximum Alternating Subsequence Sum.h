// 1911. Maximum Alternating Subsequence Sum
// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

// Runtime: 144 ms, faster than 97.60% of C++ online submissions for Maximum Alternating Subsequence Sum.
// Memory Usage: 91.2 MB, less than 59.55% of C++ online submissions for Maximum Alternating Subsequence Sum.
    
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long a = nums[0]; // length_array(a) % 2 == 1
        long long b = 0;       // length_array(b) % 2 == 0
        for (int i = 1; i < nums.size(); ++i) {
            auto ta = a;
            auto tb = b;
            a = max(ta, tb + nums[i]);
            b = max(tb, ta - nums[i]);
        }
        return max(a, b);
    }
};