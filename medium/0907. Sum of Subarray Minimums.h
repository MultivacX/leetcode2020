// 907. Sum of Subarray Minimums

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