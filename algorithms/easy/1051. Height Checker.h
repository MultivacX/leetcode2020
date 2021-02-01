// 1051. Height Checker
// https://leetcode.com/problems/height-checker/

// Runtime: 4 ms, faster than 71.31% of C++ online submissions for Height Checker.
// Memory Usage: 8.8 MB, less than 13.37% of C++ online submissions for Height Checker.
    
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        sort(begin(tmp), end(tmp));
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i)
            if (heights[i] != tmp[i]) ++ans;
        return ans;
    }
};