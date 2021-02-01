// 1673. Find the Most Competitive Subsequence
// https://leetcode.com/problems/find-the-most-competitive-subsequence/

// Runtime: 360 ms, faster than 81.62% of C++ online submissions for Find the Most Competitive Subsequence.
// Memory Usage: 110 MB, less than 33.09% of C++ online submissions for Find the Most Competitive Subsequence.
    
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N == k) return nums;
        if (1 == k) return {*min_element(begin(nums), end(nums))};
        
        vector<int> ans{nums[0]};
        for (int i = 1; i < N; ++i) {
            while (ans.size() > 0 && ans.size() + N - i > k && ans.back() > nums[i])
                ans.pop_back();
            if (ans.size() < k) 
                ans.push_back(nums[i]);
        }
        return ans;
    }
};