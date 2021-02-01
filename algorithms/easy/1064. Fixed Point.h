// 1064. Fixed Point
// https://leetcode.com/problems/fixed-point/

// Runtime: 16 ms, faster than 63.92% of C++ online submissions for Fixed Point.
// Memory Usage: 10.7 MB, less than 96.91% of C++ online submissions for Fixed Point.
    
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0;
        int r = A.size();
        int i = -1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m == A[m]) {
                i = m;
                r = m;
            }
            else if (m > A[m]) l = m + 1;
            else r = m;
        }
        return i;
    }
};