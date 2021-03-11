// 920. Number of Music Playlists
// https://leetcode.com/problems/number-of-music-playlists/

// Runtime: 8 ms, faster than 54.17% of C++ online submissions for Number of Music Playlists.
// Memory Usage: 9.2 MB, less than 52.50% of C++ online submissions for Number of Music Playlists.
    
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        static const uint64_t M = 1000000007;
        vector<vector<uint64_t>> dp(L + 1, vector<uint64_t>(N + 1, 0));
        dp[0][0] = 1;
        for (int l = 1; l <= L; ++l) {
            for (int n = 1; n <= N; ++n) {
                // songs[1, ..., n - 1]: play cur song from songs[n, N]
                uint64_t a = dp[l - 1][n - 1] * (uint64_t)(N - (n - 1)) % M;
                // play cur song from songs[1, ..., n], n > K
                uint64_t b = dp[l - 1][n] * (uint64_t)max(0, n - K) % M;
                dp[l][n] = (a + b) % M;
            }
        }
        return dp[L][N] % M;
    }
};