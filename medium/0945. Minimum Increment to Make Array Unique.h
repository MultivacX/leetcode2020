// 945. Minimum Increment to Make Array Unique

// Runtime: 120 ms, faster than 38.64% of C++ online submissions for Minimum Increment to Make Array Unique.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Minimum Increment to Make Array Unique.

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        const int N = A.size();
        if (N <= 1) return 0;
        
        sort(begin(A), end(A));
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            if (A[i] <= A[i - 1]) {
                ans += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return ans;
    }
};