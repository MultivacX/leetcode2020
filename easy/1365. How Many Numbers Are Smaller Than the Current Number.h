// 1365. How Many Numbers Are Smaller Than the Current Number
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// Runtime: 12 ms, faster than 77.44% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
// Memory Usage: 10.8 MB, less than 23.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
    
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(begin(sorted), end(sorted));
        
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            ans[i] = lower_bound(begin(sorted), end(sorted), nums[i]) - begin(sorted);
        return ans;
    }
};