// 1829. Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query/

// Runtime: 136 ms, faster than 71.43% of C++ online submissions for Maximum XOR for Each Query.
// Memory Usage: 96.9 MB, less than 42.86% of C++ online submissions for Maximum XOR for Each Query.
    
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int v = (1 << maximumBit) - 1;
        int val = 0; 
        for (int i : nums) val ^= i;
        
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            // int k = 0;
            // for (int j = maximumBit - 1; j >= 0; --j) {
            //     if (val & (1 << j)) continue;
            //     k |= 1 << j;
            // }
            int k = (~(val & v)) & v;
            ans.push_back(k);
            val ^= nums[i];
        }
        return ans;
    }
};