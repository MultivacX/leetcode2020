// 398. Random Pick Index

// Runtime: 128 ms, faster than 47.42% of C++ online submissions for Random Pick Index.
// Memory Usage: 34.6 MB, less than 10.00% of C++ online submissions for Random Pick Index.

// Time Complexity: O(nums.size()).
// Space Complexity: O(1).

class Solution {
public:
    Solution(vector<int>& nums) : _nums(nums) {
        
    }
    
    int pick(int target) {
        int ans = -1;
        int cnt = 0;
        for (int i = 0; i < _nums.size(); ++i) {
            if (target != _nums[i]) continue;
            
            ++cnt;
            if (rand() % cnt == 0)
                ans = i;
        }
        return ans;
    }
    
    const vector<int>& _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// Runtime: 236 ms, faster than 9.78% of C++ online submissions for Random Pick Index.
// Memory Usage: 52.8 MB, less than 10.00% of C++ online submissions for Random Pick Index.
/*class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return m[target][rand() % m[target].size()];
    }
    
    unordered_map<int, vector<int>> m;
};*/