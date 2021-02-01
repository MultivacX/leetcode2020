// 1695. Maximum Erasure Value
// https://leetcode.com/problems/maximum-erasure-value/

// Runtime: 580 ms, faster than 65.94% of C++ online submissions for Maximum Erasure Value.
// Memory Usage: 114.8 MB, less than 43.54% of C++ online submissions for Maximum Erasure Value.
    
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0, sum = 0;
        unordered_set<int> sub;
        for (int i = 0; i < N; ++i) {
            if (sub.insert(nums[i]).second) {
                sum += nums[i];
            } else {
                for (int l = i - sub.size(); l < i && nums[l] != nums[i]; ++l) {
                    sub.erase(nums[l]);
                    sum -= nums[l];
                }
            }
            
            if (ans < sum) ans = sum;
        }
        return ans;
    }
};