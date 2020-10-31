// 698. Partition to K Equal Sum Subsets

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition to K Equal Sum Subsets.
// Memory Usage: 9.5 MB, less than 5.03% of C++ online submissions for Partition to K Equal Sum Subsets.

class Solution {    
    bool partition(vector<int>& nums, int k, int target, int curSum, int start, vector<bool>& visited) {
        if (k == 1) return true;
        if (target < curSum) return false;
        
        // start to find a new 1 subset
        if (target == curSum) return partition(nums, k - 1, target, 0, 0, visited);
        
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            if (partition(nums, k, target, curSum + nums[i], i + 1, visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % k) return false;
        if (sum == 0) return true;
        
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return partition(nums, k, sum / k, 0, 0, visited);
    }
};

/*class Solution {    
    bool test(vector<int>& nums, int targetSum, int currentSum, int k, int& used) {
        if (targetSum == currentSum) {
            if (--k == 0) return true;
            currentSum = 0;
        } else if (targetSum < currentSum) {
            return false;
        }
        
        for (int j = 0; j < nums.size(); ++j) {
            if (used & (1 << j)) continue;
                
            used |= (1 << j);
            if (test(nums, targetSum, currentSum + nums[j], k, used))
                return true;
            used &= ~(1 << j);
        }
        
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % k) return false;
        if (sum == 0) return true;
        
        int used = 0;
        return test(nums, sum / k, 0, k, used);
    }
};*/

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