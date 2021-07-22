// 1940. Longest Common Subsequence Between Sorted Arrays
// https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/

// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Longest Common Subsequence Between Sorted Arrays.
// Memory Usage: 15.4 MB, less than 100.00% of C++ online submissions for Longest Common Subsequence Between Sorted Arrays.
    
class Solution {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
        array<int, 101> counts{0};
        for (const auto& v : arrays) 
            for (int i : v)
                ++counts[i];
        
        const int n = arrays.size();
        vector<int> ans;
        for (int i = 1; i <= 100; ++i)
            if (counts[i] == n)
                ans.push_back(i);
        return ans;
    }
};