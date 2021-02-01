// 813. Largest Sum of Averages

// Runtime: 48 ms, faster than 11.66% of C++ online submissions for Largest Sum of Averages.
// Memory Usage: 41.4 MB, less than 50.00% of C++ online submissions for Largest Sum of Averages.

// Runtime: O(N*N*K).
// Memory: O(N*N*K).

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        const int N = A.size();
        vector<double> S(N, 0);
        S[0] = A[0];
        for (int i = 1; i < N; ++i) S[i] = S[i - 1] + A[i];
        vector<vector<vector<double>>> m(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return get_sum(S, 0, N - 1, K, m);
    }
    
    double get_sum(const vector<double>& S, int i, int j, int K, vector<vector<vector<double>>>& m) {
        // [i, j] -> K groups
        // 0 <= i <= j < N
        if (K == 1) return (S[j] - (i > 0 ? S[i - 1] : 0)) / (j - i + 1);
        if (m[i][j][K] != 0) return m[i][j][K];
        for (int k = i + K - 1; k <= j; ++k)
            m[i][j][K] = max(m[i][j][K], get_sum(S, i, k - 1, K - 1, m) + get_sum(S, k, j, 1, m));
        return m[i][j][K];
    }
};