// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Missing Ranges.
// Memory Usage: 7.4 MB, less than 69.73% of C++ online submissions for Missing Ranges.
    
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.insert(nums.begin(), -2000000000);
        nums.push_back(2000000000);
        const int N = nums.size();
        vector<string> ans;
        for (int i = 0; i + 1 < N; ++i) {
            // [nums[i]+1, nums[i+1]-1]
            int l = max(lower, nums[i] + 1);
            int u = min(upper, nums[i + 1] - 1);
            if (l < u) ans.push_back(to_string(l) + "->" + to_string(u));
            else if (l == u) ans.push_back(to_string(l));
        }
        return ans;
    }
};


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) 
            return lower == upper ? 
                    vector<string>{to_string(lower)} : 
                    vector<string>{to_string(lower) + "->" + to_string(upper)};
        if (lower == upper) 
            return {};
        
        const int n = nums.size();
        vector<string> ans;
        if (lower < nums[0]) {
            if (lower == nums[0] - 1) ans.push_back(to_string(lower));
            else ans.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            if (diff == 1) continue;
            if (diff == 2) ans.push_back(to_string(nums[i] - 1));
            else ans.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
        }
        if (nums[n - 1] < upper) {
            if (nums[n - 1] == upper - 1) ans.push_back(to_string(upper));
            else ans.push_back(to_string(nums[n - 1] + 1) + "->" + to_string(upper));
        }
        return ans;
    }
};