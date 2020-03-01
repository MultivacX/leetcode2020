// 565. Array Nesting

// Runtime: 20 ms, faster than 86.49% of C++ online submissions for Array Nesting.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Array Nesting.

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f(nums, i, 0));
        }
        return ans;
    }
    
    int f(vector<int>& nums, int start, int len) {
        const int n = nums.size();
        if (start >= n || nums[start] > 20000) {
            return len;
        }
        int next = nums[start];
        nums[start] += 30000;
        return f(nums, next, len + 1);
    }
};