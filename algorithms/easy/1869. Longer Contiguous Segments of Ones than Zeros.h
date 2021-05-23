// 1869. Longer Contiguous Segments of Ones than Zeros
// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
// Memory Usage: 6 MB, less than 85.71% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
    
class Solution {
public:
    bool checkZeroOnes(string s) {
        int m0 = 0, m1 = 0;
        int l0 = 0, l1 = 0;
        for (char c : s) {
            if (c == '0') {
                l1 = 0;
                m0 = max(m0, ++l0);
            } else {
                l0 = 0;
                m1 = max(m1, ++l1);
            }
        }
        return m0 < m1;
    }
};