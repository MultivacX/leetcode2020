// 1784. Check if Binary String Has at Most One Segment of Ones
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Binary String Has at Most One Segment of Ones.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Check if Binary String Has at Most One Segment of Ones.
    
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < s.length() && s[i] == '1') ++i;
        while (j >= 0 && s[j] == '0') --j;
        return i >= j;
    }
};