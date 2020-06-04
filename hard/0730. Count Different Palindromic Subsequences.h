// 730. Count Different Palindromic Subsequences
// https://leetcode.com/problems/count-different-palindromic-subsequences/

// Runtime: 108 ms, faster than 87.87% of C++ online submissions for Count Different Palindromic Subsequences.
// Memory Usage: 36.4 MB, less than 100.00% of C++ online submissions for Count Different Palindromic Subsequences.

class Solution {
    int64_t count(const string& S, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j] > 0) return memo[i][j];
        
        static const int64_t MOD = 1000000007;
        const int N = S.length();
        int64_t ans = 0;
        if (S[i] == S[j]) {
            int l = i + 1;
            int r = j - 1;
            while (l < j && S[l] != S[i]) ++l;
            while (r > i && S[r] != S[i]) --r;
            if (l > r) {
                // S[i] == S[j] != S[k], k = [i+1,j-1]
                // S[i]__palindromics[i+1,j-1]__S[j] + palindromics[i+1,j-1] + S[i]__S[j] + S[i]
                ans = 2 * count(S, i + 1, j - 1, memo) + 2;
            } else if (l == r) {
                // S[i] == S[l] == S[j], i < l < j
                // S[i]__palindromics[i+1,j-1]__S[j] + palindromics[i+1,j-1] + S[i]__S[j] + S[i] - S[l]
                ans = 2 * count(S, i + 1, j - 1, memo) + 1;
            } else {
                // S[i] == S[l] == S[r] == S[j], i < l < r < j
                // S[i]__palindromics[i+1,j-1]__S[j] + palindromics[i+1,j-1] - palindromics[l+1,r-1]
                ans = 2 * count(S, i + 1, j - 1, memo) - count(S, l + 1, r - 1, memo);
            }
        } else {
            // S[i] != S[j]
            // v--|-------v      <-- [i,   j-1]
            // i i+1 ... j-1 j
            //    ^-------|--^   <-- [i+1,   j]
            //    |-------|      <-- [i+1, j-1] recounted
            ans = count(S, i, j - 1, memo) + count(S, i + 1, j, memo) - count(S, i + 1, j - 1, memo);
        }
        // avoid negative ans
        ans = (ans + MOD) % MOD;
        memo[i][j] = ans;
        return ans;
    }
    
public:
    int countPalindromicSubsequences(string S) {
        const int N = S.length();
        if (N <= 1) return N;
        
        vector<vector<int>> memo(N, vector<int>(N, 0));
        return count(S, 0, N - 1, memo);
    }
};