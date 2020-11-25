// 1621. Number of Sets of K Non-Overlapping Line Segments
// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Sets of K Non-Overlapping Line Segments.
// Memory Usage: 7 MB, less than 85.24% of C++ online submissions for Number of Sets of K Non-Overlapping Line Segments.

class Solution {
public:
    int numberOfSets(int n, int k) {
        // k line segments : k+1 points or 2*k points (k pairs point)

        // draw k line segments no share point: 2*k points (k pairs point)
        
        // 1. choose 2*k points from n+k-1 points
        // 2. using 2*k points (pair [x, y]) make k line segments, 0 <= x < y < n+k-1
        // 3. merge the point y+1 after line[x, y] to point y except the last point
        // 4. after merge k-1 points, we have n points and k line segments
        // return comb(n+k-1, 2*k)
        
        const int64_t MOD = 1000000007;
        int N = n + k - 1, K = 2 * k;
        // cout << N << ", " << K << endl;

        int64_t nx = 1;
        // i!
        for (int64_t i = 2; i <= N; ++i) nx = nx * i % MOD;

        const int M = max(K, N - K) + 1;
        vector<int64_t> inv(M, 0), inv_kx(M, 0);
        inv[0] = inv_kx[0] = inv[1] = inv_kx[1] = 1;
        // https://cp-algorithms.com/algebra/module-inverse.html
        // 1 / i!
        for (int64_t i = 2; i < M; ++i) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
            inv_kx[i] = inv_kx[i - 1] * inv[i] % MOD;
            // cout << i << ":" << inv_kx[i] << "  ";
        }
        
        // N! / (K! * (N - K)!)
        return nx * inv_kx[K] % MOD * inv_kx[N - K] % MOD;
    }
};