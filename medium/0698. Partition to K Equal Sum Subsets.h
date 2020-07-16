// 698. Partition to K Equal Sum Subsets

// Time Limit Exceeded
// 149 / 149 test cases passed, but took too long.
/*class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return f(nums, k, sum / k, 0, 0, visited);
    }
    
    bool f(const vector<int>& nums, int k, const int target, int sum, int idx, vector<bool>& visited) {
        if (k == 1) return true;
        if (target == sum) return f(nums, k - 1, target, 0, 0, visited);
        
        for (int i = idx, last_idx = -1; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (last_idx > 0 && nums[last_idx] == nums[i]) continue;
            if (target < sum + nums[i]) break;
            
            last_idx = i;
            visited[i] = true;
            if (f(nums, k, target, sum + nums[i], idx + 1, visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};*/

// Time Limit Exceeded
// 54 / 149 test cases passed.
/*class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return f(nums, k, sum / k, 0, visited);
    }
    
    bool f(const vector<int>& nums, int k, const int target, int sum, vector<bool>& visited) {
        if (k == 1) return true;
        if (target == sum) return f(nums, k - 1, target, 0, visited);
        
        for (int i = 0, last_idx = -1; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (last_idx > 0 && nums[last_idx] == nums[i]) continue;
            if (target < sum + nums[i]) break;
            
            last_idx = i;
            visited[i] = true;
            if (f(nums, k, target, sum + nums[i], visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};*/

// Time Limit Exceeded
// 8 / 149 test cases passed.
/*class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return f(nums, k, sum / k, 0, visited);
    }
    
    bool f(const vector<int>& nums, int k, const int target, int sum, vector<bool>& visited) {
        if (k == 1) return true;
        if (target == sum) return f(nums, k - 1, target, 0, visited);
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (target < sum + nums[i]) break;
            
            visited[i] = true;
            if (f(nums, k, target, sum + nums[i], visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};*/