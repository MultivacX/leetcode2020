// 1879. Minimum XOR Sum of Two Arrays
// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

// Runtime: 28 ms, faster than 56.46% of C++ online submissions for Minimum XOR Sum of Two Arrays.
// Memory Usage: 18.1 MB, less than 24.95% of C++ online submissions for Minimum XOR Sum of Two Arrays.

class Solution {
    int m;
    int n;
    vector<vector<int>> memo;
    
    int sum(vector<int>& nums1, vector<int>& nums2, int i, int mask) {
        if (i >= m) return 0;
        if (memo[i][mask] != INT_MAX) return memo[i][mask];
        
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            int bit = 1 << j;
            if ((mask & bit) == 0) {
                ans = min(ans, (nums1[i] ^ nums2[j]) + sum(nums1, nums2, i + 1, mask | bit));
            }
        }
        memo[i][mask] = ans;
        return ans;
    }
    
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memo.resize(m, vector<int>(1 << n, INT_MAX));
        return sum(nums1, nums2, 0, 0);
    }
};