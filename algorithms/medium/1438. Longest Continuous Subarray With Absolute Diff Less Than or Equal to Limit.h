// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Runtime: 320 ms, faster than 26.82% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
// Memory Usage: 60.9 MB, less than 100.00% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.

// Time Complexity: O(nums.size() * lg(nums.size())).
// Space Complexity: O(nums.size()).

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 1) return 1;
        
        // {num, max_idx}
        map<int, int> n2i;
        int ans = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (n2i.empty()) {
                n2i.emplace(nums[j], j);
                i = j;
                ans = max(ans, j - i + 1);
                continue;
            } 
            
            bool checkMin = abs(nums[j] - n2i.begin()->first) <= limit;
            bool checkMax = abs(nums[j] - n2i.rbegin()->first) <= limit;
            
            if (checkMin && checkMax) {
                // n2i.begin() <= nums[j] <= n2i.rbegin()
                n2i.insert_or_assign(nums[j], j);
            } else if (!checkMin && !checkMax) {
                // nums[j] + limit < n2i.begin() <= n2i.rbegin()
                // n2i.begin() <= n2i.rbegin() < nums[j] + limit
                n2i.clear();
                n2i.emplace(nums[j], j);
                i = j;
            } else if (checkMin) {
                // nums[j] + limit <= n2i.begin() < n2i.rbegin()
                auto it = n2i.rbegin();
                int k = it->second;
                while (it->first - nums[j] > limit) {
                    k = max(k, it->second);
                    ++it;
                }
                while (i <= k) n2i.erase(nums[i++]);
                n2i.insert_or_assign(nums[j], j);
            } else {
                // n2i.begin() < n2i.rbegin() <= nums[j] + limit
                auto it = n2i.begin();
                int k = it->second;
                while (nums[j] - it->first > limit) {
                    k = max(k, it->second);
                    ++it;
                }
                while (i <= k) n2i.erase(nums[i++]);
                n2i.insert_or_assign(nums[j], j);
            }
            
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};