// 891. Sum of Subsequence Widths
// https://leetcode.com/problems/sum-of-subsequence-widths/

// Runtime: 184 ms, faster than 43.66% of C++ online submissions for Sum of Subsequence Widths.
// Memory Usage: 29 MB, less than 35.00% of C++ online submissions for Sum of Subsequence Widths.

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int64_t M = 1000000007;
        const int N = A.size();
        if (N == 1) return 0;
        
        sort(begin(A), end(A));

        vector<int64_t> P(N, 1);
        for (int i = 1; i < N; ++i) 
            P[i] = P[i - 1] * 2 % M;
        
        // SUM((A[j] - A[i]) * 2 ^ (j - i - 1)), 0 <= i < j < N
        // SUM(A[j] * 2 ^ (j - i - 1)) - SUM(A[i] * 2 ^ (j - i - 1))
        
        // A[j] * (2 ^ j - 1), 0 < j < N
        // -A[i] * (2 ^ (N - 1 - i) - 1), 0 <= i < N - 1

        int64_t sum = 0;
        for (int i = 0, j = 1; j < N; ++i, ++j) 
            sum = (sum + A[j] * (P[j] - 1) % M - A[i] * (P[N - 1 - i] - 1) % M) % M;
        return sum;
    }
};

// Time Limit Exceeded
// 57 / 64 test cases passed.
/*class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int64_t M = 1000000007;
        const int N = A.size();
        
        sort(begin(A), end(A));
        
        vector<int64_t> B(N, 0);
        B[0] = A[0];
        for (int i = 1; i < N; ++i)
            B[i] = B[i - 1] + A[i];

        vector<int64_t> P(N, 1);
        for (int i = 1; i < N; ++i) 
            P[i] = P[i - 1] * 2 % M;

        int64_t sum = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                int64_t width = (A[i] - A[j]) % M;
                sum = (sum + width * P[i - j - 1] % M) % M;
            }
        }
        return sum;
    }
};*/