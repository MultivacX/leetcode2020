// 228. Summary Ranges

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
// Memory Usage: 8.5 MB, less than 84.62% of C++ online submissions for Summary Ranges.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        
        vector<pair<int, int>> ranges{{nums[0], nums[0]}};
        for (int i = 1; i < n; ++i) {
            if (nums[i] - 1 == ranges.back().second) {
                ranges.back().second = nums[i];
            } else {
                ranges.emplace_back(nums[i], nums[i]);
            }
        }
        
        vector<string> ans;
        for (const auto& r : ranges) {
            if (r.first == r.second) {
                ans.emplace_back(to_string(r.first));
            } else {
                ans.emplace_back(to_string(r.first) + "->" + to_string(r.second));
            }
        }
        return ans;
    }
};