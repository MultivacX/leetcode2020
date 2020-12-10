// 246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Strobogrammatic Number.
// Memory Usage: 6.4 MB, less than 65.30% of C++ online submissions for Strobogrammatic Number.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = (int)num.length() - 1;
        while (i <= j) {
            if (num[i] == '0' || num[i] == '1' || num[i] == '8') {
                if (num[i++] != num[j--]) return false;
            } else if (num[i] == '6') {
                if (num[j] != '9') return false;
                ++i; --j;
            } else if (num[i] == '9') {
                if (num[j] != '6') return false;
                ++i; --j;
            } else {
                return false;
            }
        }
        return true;
    }
};