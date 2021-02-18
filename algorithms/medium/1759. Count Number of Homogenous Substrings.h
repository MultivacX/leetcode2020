// 1759. Count Number of Homogenous Substrings
// https://leetcode.com/problems/count-number-of-homogenous-substrings/

// Runtime: 32 ms, faster than 59.85% of C++ online submissions for Count Number of Homogenous Substrings.
// Memory Usage: 11.7 MB, less than 59.91% of C++ online submissions for Count Number of Homogenous Substrings.
    
class Solution {
public:
    int countHomogenous(string s) {
        const int n = s.length();
        int i = 0;
        uint64_t ans = 0;
        for (int j = 1; j <= n; ++j) {
            if (j == n || s[i] != s[j]) {
                uint64_t l = j - i;
                ans = (ans + l * (l + 1) / 2 % 1000000007) % 1000000007;
            }
            
            if (j < n && s[i] != s[j]) i = j;
        }
        return ans;
    }
};