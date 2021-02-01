// 258. Add Digits
// https://leetcode.com/problems/add-digits/

// Runtime: 4 ms, faster than 44.46% of C++ online submissions for Add Digits.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Add Digits.

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int ans = 0;
        while (num) {
            ans += num % 10;
            // ans is always < 19
            while (ans >= 10) 
                ans = ans - 10 + 1;
            num /= 10;
        }
        return ans;
    }
};