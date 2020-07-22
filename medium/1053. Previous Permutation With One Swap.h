// 1053. Previous Permutation With One Swap
// https://leetcode.com/problems/previous-permutation-with-one-swap/

// Runtime: 56 ms, faster than 86.08% of C++ online submissions for Previous Permutation With One Swap.
// Memory Usage: 24.8 MB, less than 62.92% of C++ online submissions for Previous Permutation With One Swap.

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        // [0, l] [l+1, j-1] [j, k] [k+1, n-1]
        
        // x, y = [l+1, n-1] : A[x] <= A[y], x < y
        // A[l] > A[l+1]
        
        // i0 = [l+1, j-1] : A[i0] < A[i1]
        // i1, x, y = [j, k] : A[i1] < A[l] & A[x] == A[y], x != y
        // i2 = [l+1, j-1] : A[i2] >= A[l]
        
        const int N = A.size();
        if (N == 1) return A;
        
        int l = N - 2;
        while (l >= 0 && A[l] <= A[l + 1]) --l;
        if (l < 0) return A;
        
        // for (int i = 0; i <= l; ++i) cout << A[i] << " "; cout << endl;
        // for (int i = l + 1; i < N; ++i) cout << A[i] << " "; cout << endl;
        
        int j = N - 1;
        while (A[j] >= A[l]) --j; // i2
        while (A[j] == A[j - 1]) --j; // i1
        swap(A[l], A[j]);
        return A;
    }
};