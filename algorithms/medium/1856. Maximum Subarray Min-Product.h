// 1856. Maximum Subarray Min-Product
// https://leetcode.com/problems/maximum-subarray-min-product/

// Runtime: 264 ms, faster than 72.09% of C++ online submissions for Maximum Subarray Min-Product.
// Memory Usage: 90.3 MB, less than 60.59% of C++ online submissions for Maximum Subarray Min-Product.
    
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        // bounds[i] = {l, r}
        // nums[i] <= nums[l ... r]
        // nums[i] >  nums[l-1] 
        // nums[i] >  nums[r+1]
        const int n = nums.size();
        
        vector<int64_t> prefix(n + 1);
        vector<int> lb(n), rb(n);
        
        stack<int> s; s.push(-1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
            while (s.top() != -1 && nums[s.top()] >= nums[i])
                s.pop();
            lb[i] = s.top() + 1;
            s.push(i);
        }
        
        s = {}; s.push(n);
        for (int i = n - 1; i >= 0; --i) {
            while (s.top() != n && nums[s.top()] >= nums[i])
                s.pop();
            rb[i] = s.top() - 1;
            s.push(i);
        }
        // for (int i = 0; i < n; ++i) printf("[%d %d %d] ", lb[i], i, rb[i]);
        
        int64_t product = 0;
        for (int i = 0; i < n; ++i) {
            int l = lb[i], r = rb[i];
            product = max(product, nums[i] * (prefix[r + 1] - prefix[l]));
        }
        return product % 1000000007;
    }
};