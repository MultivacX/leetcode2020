// 1027. Longest Arithmetic Sequence
// https://leetcode.com/problems/longest-arithmetic-sequence/

// Runtime: 3300 ms, faster than 38.49% of C++ online submissions for Longest Arithmetic Sequence.
// Memory Usage: 193.3 MB, less than 86.67% of C++ online submissions for Longest Arithmetic Sequence.

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = 0;
        // {A[i_k] - A[i_(k-1)], {i_k, k}}
        unordered_map<int, unordered_map<int, int>> m;
        for (int i = 0; i + 1 < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int diff = A[j] - A[i];
                m[diff][j] = m[diff].count(i) ? m[diff][i] + 1 : 2;
                ans = max(ans, m[diff][j]);
            }
        }
        return ans;
    }
};