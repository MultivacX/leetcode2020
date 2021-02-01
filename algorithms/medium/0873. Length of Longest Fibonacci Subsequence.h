// 873. Length of Longest Fibonacci Subsequence

// Runtime: 312 ms, faster than 62.21% of C++ online submissions for Length of Longest Fibonacci Subsequence.
// Memory Usage: 10.2 MB, less than 28.57% of C++ online submissions for Length of Longest Fibonacci Subsequence.

// Time Complexity: O(N * N).
// Space Complexity: O(N * lg(A[N-1])).

class Solution {
    int ans = 0;
    
public:
    int lenLongestFibSubseq(vector<int>& A) {
        const int N = A.size();
        // {a, b}
        unordered_map<int, unordered_set<int>> B;
        unordered_set<int> S(begin(A), end(A));
        for (int i = 0; i < N - 2; ++i) {
            for (int j = i + 1; j < N - 1 && A[i] + A[j] <= A[N - 1]; ++j) {
                f(S, B, A[i], A[j], A[N - 1], 2);
            }
        }
        return ans <= 2 ? 0 : ans;
    }
    
    void f(const unordered_set<int>& S, unordered_map<int, unordered_set<int>>& B, int a, int b, const int max_val, int len) {
        int c = a + b;
        if (c > max_val || S.count(c) == 0 || B[a].count(b)) {
            ans = max(ans, len);
            return;
        }
        
        B[a].insert(b);
        f(S, B, b, c, max_val, len + 1);
    }
};