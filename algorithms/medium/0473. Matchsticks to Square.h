// 473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/

// Runtime: 76 ms, faster than 64.58% of C++ online submissions for Matchsticks to Square.
// Memory Usage: 10 MB, less than 5.21% of C++ online submissions for Matchsticks to Square.

class Solution {
    bool helper(vector<int>& nums, vector<bool>& visited, int target, int curSide, int cnt, int idx) {
        if (cnt == 3) return true;
        if (target < curSide) return false;
        if (target == curSide) return helper(nums, visited, target, 0, cnt + 1, 0);
        
        for (int i = idx; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(nums, visited, target, curSide + nums[i], cnt, i + 1)) 
                return true;
            visited[i] = false;
        }
        return false;
    }
    
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 4) return false;
        
        sort(nums.rbegin(), nums.rend());
        vector<bool> visited(nums.size(), false);
        return helper(nums, visited, sum / 4, 0, 0, 0);
    }
};