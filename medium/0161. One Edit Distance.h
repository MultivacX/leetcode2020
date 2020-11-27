// 161. One Edit Distance
// https://leetcode.com/problems/one-edit-distance/

// Runtime: 4 ms, faster than 56.72% of C++ online submissions for One Edit Distance.
// Memory Usage: 6.9 MB, less than 61.21% of C++ online submissions for One Edit Distance.
    
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int M = s.length();
        const int N = t.length();
        if (M + 1 == N) {
            int i = 0, j = 0, d = 0;
            while (j < N) {
                if (i < M && s[i] == t[j]) {
                    ++i, ++j;
                    continue;
                } else {
                    // insert before s[i]
                    ++j;
                    if (++d > 1) 
                        return false;
                }
            }
            return i + 1 == j;
        } else if (M - 1 == N) {
            int i = 0, j = 0, d = 0;
            while (i < M) {
                if (j < N && s[i] == t[j]) {
                    ++i, ++j;
                    continue;
                } else {
                    // delete s[i]
                    ++i;
                    if (++d > 1) 
                        return false;
                }
            }
            return i - 1 == j;
        } else if (M == N) {
            int r = 0;
            for (int i = 0; i < M; ++i) {
                if (s[i] == t[i]) continue;
                // replace s[i]
                if (++r > 1) return false;
            }
            return r == 1;
        } else {
            return false;
        }
    }
};