// 1785. Minimum Elements to Add to Form a Given Sum
// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

// Runtime: 120 ms, faster than 100.00% of C++ online submissions for Minimum Elements to Add to Form a Given Sum.
// Memory Usage: 73.4 MB, less than 100.00% of C++ online submissions for Minimum Elements to Add to Form a Given Sum.
    
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t diff = goal;
        for (int64_t i : nums) diff -= i;
        diff = abs(diff);
        return diff / limit + (diff % limit == 0 ? 0 : 1);
    }
};