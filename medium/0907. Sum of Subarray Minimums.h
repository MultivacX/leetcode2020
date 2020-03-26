// 907. Sum of Subarray Minimums

// ERROR
/* class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int N = A.size();
        
        vector<int> L(N, 0);
        for (int i = 1; i < N; ++i)
            L[i] = A[i] <= A[L[i - 1]] ? i : L[i - 1];
        
        vector<int> R(N, N - 1);
        for (int i = N - 2; i >= 0; --i)
            R[i] = A[i] < A[R[i + 1]] ? i : R[i + 1];
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {   
            int l = 0;
            if (i != L[i]) {
                if (A[i] == A[L[i]]) l = L[i] + 1;
                else l = i;
            }

            int r = N - 1;
            if (i != R[i]) {
                if (A[i] == A[R[i]]) r = R[i] - 1;
                else r = i;
            }

            int lcnt = i - l + 1;
            int rcnt = r + 1 - i;
            ans = (ans + lcnt * rcnt % 1000000007 * A[i] % 1000000007) % 1000000007;
            printf("L[%d]=%d, R[%d]=%d, \n", i, L[i], i, R[i]);
            printf("[%d, %d] %d * %d * %d = %d\n\n", l, r, lcnt, rcnt, A[i], lcnt * rcnt * A[i]);
        }
        return ans;
    }
}; */

// Time Limit Exceeded
// 96 / 100 test cases passed.
/* class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int N = A.size();
        int ans = 0;
        find(A, 0, N, ans);
        return ans;
    }
    
    void find(vector<int>& A, int s, int e, int& ans) {
        if (s >= e) return;
        
        auto it = min_element(A.begin() + s, A.begin() + e);
        int idx = distance(A.begin(), it);
        
        // printf("[%d, %d) : %d\n", s, e, A[idx]);
        ans = (ans + A[idx] * (idx - s + 1) * (e - idx) % 1000000007) % 1000000007;
        
        find(A, s, idx, ans);
        find(A, idx + 1, e, ans);
    }
}; */

// Time Limit Exceeded
// 92 / 100 test cases passed.
/* class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int N = A.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int min_val = INT_MAX;
            for (int j = i; j < N; ++j) {
                min_val = min(min_val, A[j]);
                ans = (ans + min_val) % 1000000007; 
            }
        }
        return ans;
    }
}; */