// 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/

// Runtime: 4 ms, faster than 99.67% of C++ online submissions for Richest Customer Wealth.
// Memory Usage: 7.7 MB, less than 99.99% of C++ online submissions for Richest Customer Wealth.
    
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        for (const auto& v : accounts)
            sum = max(sum, accumulate(begin(v), end(v), 0));
        return sum;
    }
};