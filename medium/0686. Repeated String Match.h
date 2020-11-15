// 686. Repeated String Match

// Runtime: 1252 ms, faster than 11.10% of C++ online submissions for Repeated String Match.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Repeated String Match.

// Time Complexity: O(M * N).
// Space Complexity: O(1).

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        const int M = A.size();
        const int N = B.size();
        for (int i = 0; i < M; ++i) {
            int j = i;
            int k = 0;
            int times = 1;
            while (k < N) {
                if (j == M) j = 0, ++times;
                if (A[j] != B[k]) break;
                ++j;
                ++k;
            }
            if (k == N) return times;
        }
        return -1;
    }
};