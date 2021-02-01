// 1031. Maximum Sum of Two Non-Overlapping Subarrays

// Runtime: 4 ms, faster than 89.27% of C++ online submissions for Maximum Sum of Two Non-Overlapping Subarrays.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Maximum Sum of Two Non-Overlapping Subarrays.

// Runtime: O(N).
// Memory: O(N).

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        const int N = A.size();
        
        int ans = 0;
        
        auto LL = lsub_max_sum(A, L);
        auto RM = rsub_max_sum(A, M);
        for (int i = L - 1; i + M < N; ++i)
            ans = max(ans, LL[i] + RM[i + 1]);
        
        // for (int i : LL) cout << i << ","; cout << endl;
        // for (int i : RM) cout << i << ","; cout << endl;
        
        auto LM = lsub_max_sum(A, M);
        auto RL = rsub_max_sum(A, L);
        for (int i = M - 1; i + L < N; ++i)
            ans = max(ans, LM[i] + RL[i + 1]);
        
        // for (int i : LM) cout << i << ","; cout << endl;
        // for (int i : RL) cout << i << ","; cout << endl;
        
        return ans;
    }
    
    vector<int> lsub_max_sum(const vector<int>& A, int k) {
        const int N = A.size();
        
        // S[i] = MAX(SUM[0, k - 1], ..., SUM[i - k + 1, i])
        int sum = 0;
        vector<int> S(N, 0);
        for (int i = 0; i < k; ++i)
            S[k - 1] += A[i];
        sum = S[k - 1];
        for (int i = k; i < N; ++i) {
            sum = sum + A[i] - A[i - k];
            S[i] = max(S[i - 1], sum);
        }
        return S;
    }
    
    vector<int> rsub_max_sum(const vector<int>& A, int k) {
        const int N = A.size();
        
        // S[i] = MAX(SUM[i, i + k - 1], ..., SUM[N - k, N - 1])
        int sum = 0;
        vector<int> S(N, 0);
        for (int i = N - 1; i >= N - k; --i)
            S[N - k] += A[i];
        sum = S[N - k];
        for (int i = N - k - 1; i >= 0; --i) {
            sum = sum + A[i] - A[i + k];
            S[i] = max(S[i + 1], sum);
        }
        return S;
    }
};