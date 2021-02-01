// 907. Sum of Subarray Minimums

// Runtime: 124 ms, faster than 23.77% of C++ online submissions for Sum of Subarray Minimums.
// Memory Usage: 14 MB, less than 71.43% of C++ online submissions for Sum of Subarray Minimums.

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int N = A.size();
        
        stack<int> S;
        S.push(0);
        vector<int> L(N, 0);
        for (int i = 1; i < N; ++i) {
            while (!S.empty() && A[S.top()] >= A[i])
                S.pop();
            L[i] = S.empty() ? 0 : S.top() + 1;
            S.push(i);
        }
            
        S = stack<int>();
        S.push(N - 1);
        vector<int> R(N, N - 1);
        for (int i = N - 2; i >= 0; --i) {
            while (!S.empty() && A[S.top()] > A[i])
                S.pop();
            R[i] = S.empty() ? N - 1 : S.top() - 1;
            S.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {   
            int64_t cnt = A[i] * (i - L[i] + 1) * (R[i] - i + 1) % 1000000007;
            ans = (ans + cnt) % 1000000007;
            
            // printf("L[%d]=%d, R[%d]=%d, \n", i, L[i], i, R[i]);
        }
        return ans;
    }
};

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