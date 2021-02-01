// 416. Partition Equal Subset Sum

// Runtime: 4 ms, faster than 96.56% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Partition Equal Subset Sum.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        
        sort(nums.rbegin(), nums.rend());
        return canPartition(nums, sum >> 1, 0);
    }
    
    bool canPartition(const vector<int>& nums, int sum, int i) {
        if (i >= nums.size() || nums[i] > sum) return false;
        if (nums[i] == sum) return true;
        return canPartition(nums, sum - nums[i], i + 1) || canPartition(nums, sum, i + 1);
    }
};