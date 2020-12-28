// 1180. Count Substrings with Only One Distinct Letter
// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Substrings with Only One Distinct Letter.
// Memory Usage: 6.5 MB, less than 88.67% of C++ online submissions for Count Substrings with Only One Distinct Letter.
    
class Solution {
public:
    int countLetters(string S) {
        const int N = S.length();
        int ans = 0;
        for (int i = 0, j = 0; j <= N; ++j) {
            if (j == N || S[i] != S[j]) {
                int k = j - i;
                ans += (k + 1) * k / 2;
                i = j;
            }
        }
        return ans;
    }
};