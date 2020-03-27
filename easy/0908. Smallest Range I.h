// 908. Smallest Range I

// Runtime: 20 ms, faster than 88.37% of C++ online submissions for Smallest Range I.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Smallest Range I.

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min_a = A[0];
        int max_a = A[0];
        for (int a : A) {
            min_a = min(min_a, a);
            max_a = max(max_a, a);
        }
        int diff = max_a - K - (min_a + K);
        return diff <= 0 ? 0 : diff;
    }
};