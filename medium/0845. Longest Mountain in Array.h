// 845. Longest Mountain in Array

// Runtime: 40 ms, faster than 16.48% of C++ online submissions for Longest Mountain in Array.
// Memory Usage: 18.7 MB, less than 14.29% of C++ online submissions for Longest Mountain in Array.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        int ans = 0;
        int i = 1;
        while (i < N - 1) {
            int L = i - 1;
            int R = i + 1;
            
            if (A[i] == A[R]) {
                i = R + 1;
                continue;
            }
            
            if (A[i] <= A[L] || A[i] < A[R]) {
                ++i;
                continue;
            }
            
            int cnt = 3;
            while (L > 0 && A[L - 1] < A[L]) {
                --L;
                ++cnt;
            }
            while (R + 1 < N && A[R] > A[R + 1]) {
                ++R;
                ++cnt;
            }
            ans = max(ans, cnt);
            i = R + 1;
        }
        return ans;
    }
};