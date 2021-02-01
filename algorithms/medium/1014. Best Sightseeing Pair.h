// 1014. Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair/

// Runtime: 164 ms, faster than 23.94% of C++ online submissions for Best Sightseeing Pair.
// Memory Usage: 39.6 MB, less than 41.10% of C++ online submissions for Best Sightseeing Pair.

// Time Complexity: O(N), where N is the length of A.
// Space Complexity: O(1).

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // X[i] = max(A[0] + 0, ..., A[i] + i)
        int X = A[0];
        int ans = INT_MIN;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, A[j] - j + X);
            X = max(X, A[j] + j);
        }
        return ans;
    }
};