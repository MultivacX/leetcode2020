// 1753. Maximum Score From Removing Stones
// https://leetcode.com/problems/maximum-score-from-removing-stones/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Maximum Score From Removing Stones.
// Memory Usage: 13 MB, less than 33.33% of C++ online submissions for Maximum Score From Removing Stones.

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int A = max(a, max(b, c));
        int C = min(a, min(b, c));
        int B = a + b + c - A - C;
        if (B == 0) return 0;
        
        int score = 0;
        int s = B - C;
        if (s == 0) {
            A -= 1;
            B -= 1;
            score = 1;
        } else {
            A -= s;
            B -= s;
            score = s;
        }
        return score + maximumScore(A, B, C);
    }
};