// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of All Subset XOR Totals.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Sum of All Subset XOR Totals.
    
class Solution {
    int sum = 0;
    
    void helper(const vector<int>& nums, int idx, int val) {
        sum += val;
        if (nums.size() <= idx) return;
        
        for (int i = idx; i < nums.size(); ++i) 
            helper(nums, i + 1, nums[i] ^ val);
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        helper(nums, 0, 0);
        return sum;
    }
};