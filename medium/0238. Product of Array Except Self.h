// 238. Product of Array Except Self

// Runtime: 64 ms, faster than 5.95% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 13.1 MB, less than 13.63% of C++ online submissions for Product of Array Except Self.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 1);
        vector<int> R(n, 1);
        for (int i = 0; i < n; ++i) L[i] = nums[i] * (i == 0 ? 1 : L[i - 1]);
        for (int i = n - 1; i >= 0; --i) R[i] = nums[i] * (i == n - 1 ? 1 : R[i + 1]);
        
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            ans[i] = (i == 0 ? 1 : L[i - 1]) * (i == n - 1 ? 1 : R[i + 1]);
        }
        return ans;
    }
};

// Follow up:
// Could you solve it with constant space complexity?
/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> ans(n, 1);
        ans[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i];
        }
        int product = 1;
        for (int i = n - 1; i > 0; --i) {
            ans[i] = ans[i - 1] * product;
            product *= nums[i];
        }
        ans[0] = product;
        
        return ans;
    }
};*/