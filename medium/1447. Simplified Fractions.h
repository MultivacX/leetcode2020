// 1447. Simplified Fractions
// https://leetcode.com/problems/simplified-fractions/

// Runtime: 104 ms, faster than 93.77% of C++ online submissions for Simplified Fractions.
// Memory Usage: 22 MB, less than 100.00% of C++ online submissions for Simplified Fractions.

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if (n == 1) return {};
        
        vector<string> ans;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};
