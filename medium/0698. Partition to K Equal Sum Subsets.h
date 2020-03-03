// 698. Partition to K Equal Sum Subsets

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n < k) return false;
        if (1 == k) return true;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        
        sum /= k;
    }
};