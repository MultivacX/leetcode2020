// 1945. Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Digits of String After Convert.
// Memory Usage: 6.2 MB, less than 62.34% of C++ online submissions for Sum of Digits of String After Convert.
    
class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for (char c : s) {
            int tmp = c - 'a' + 1;
            ans += tmp % 10 + tmp / 10;
        }
        --k;
        
        while (k-- > 0 && ans > 9) {
            int tmp = ans;
            ans = 0;
            while (tmp > 0) {
                ans += tmp % 10;
                tmp /= 10;   
            }
        }
        return ans;
    }
};