// 1814. Count Nice Pairs in an Array
// https://leetcode.com/problems/count-nice-pairs-in-an-array/

// Runtime: 112 ms, faster than 57.89% of C++ online submissions for Count Nice Pairs in an Array.
// Memory Usage: 56.8 MB, less than 5.01% of C++ online submissions for Count Nice Pairs in an Array.
    
class Solution {
    int rev(int i) {
        int r = 0;
        while (i) {
            r = r * 10 + i % 10;
            i /= 10;
        }
        return r;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        unordered_map<int, int> m;
        for (int i : nums) ++m[i - rev(i)];
        
        int64_t ans = 0;
        for (const auto& [i, k] : m) 
            ans = (ans + (int64_t)k * (k - 1) / 2) % 1000000007;
        return ans;
    }
};