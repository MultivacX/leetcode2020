// 907. Sum of Subarray Minimums

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