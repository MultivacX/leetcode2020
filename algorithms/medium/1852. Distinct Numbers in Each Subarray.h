// 1852. Distinct Numbers in Each Subarray
// https://leetcode.com/problems/distinct-numbers-in-each-subarray/

// Runtime: 360 ms, faster than 100.00% of C++ online submissions for Distinct Numbers in Each Subarray.
// Memory Usage: 140.4 MB, less than 100.00% of C++ online submissions for Distinct Numbers in Each Subarray.
    
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
            if (i + 1 >= k) {
                if (i + 1 > k && --m[nums[i - k]] == 0) 
                    m.erase(nums[i - k]);
                ans.push_back((int)m.size());
            }
        }
        return ans;
    }
};