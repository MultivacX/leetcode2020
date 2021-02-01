// 1221. Split a String in Balanced Strings
// https://leetcode.com/problems/split-a-string-in-balanced-strings/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split a String in Balanced Strings.
// Memory Usage: 6.4 MB, less than 72.53% of C++ online submissions for Split a String in Balanced Strings.
    
class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, val = 0;
        for (char c : s) {
            val += c == 'L' ? -1 : 1;
            if (val == 0) ++cnt;
        }
        return cnt;
    }
};