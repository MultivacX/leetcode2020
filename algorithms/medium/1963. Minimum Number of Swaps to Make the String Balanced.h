// 1963. Minimum Number of Swaps to Make the String Balanced
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

// Runtime: 104 ms, faster than 93.90% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
// Memory Usage: 31.2 MB, less than 52.08% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
    
class Solution {
public:
    int minSwaps(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '[') {
                ++l;
            } else {
                if (l > 0) {
                    --l;
                } else {
                    ++r;
                }
            }
        }
        return (r + 1) / 2;
    }
};