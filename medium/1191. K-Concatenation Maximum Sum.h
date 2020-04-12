// 1191. K-Concatenation Maximum Sum

// Runtime: 64 ms, faster than 30.96% of C++ online submissions for K-Concatenation Maximum Sum.
// Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for K-Concatenation Maximum Sum.

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        static const int M = 1000000007;
        const int N = arr.size();
        
        int L = 0;  // max sum : 0 -> i
        int LS = 0; // add from  0 -> N - 1
        
        int R = 0;  // max sum : N - 1 -> i
        int RS = 0; // add from  N - 1 -> 0
        
        int CS = 0;
        int MS = 0; // max sum : [0, N)
        for (int i = 0; i < N; ++i) {
            LS = (LS + arr[i]) % M;
            L = max(L, LS);
            
            RS = (RS + arr[N - 1 - i]) % M;
            R = max(R, RS);
            
            CS = (CS + arr[i]) % M;
            if (CS < arr[i]) CS = arr[i];
            MS = max(MS, CS);
        }
        // printf("L:%d, R:%d, SUM:%d, MAX:%d", L, R, LS, MS);
        
        if (k == 1) return MS;
        int ans = LS == MS ? MS * k % M : MS;
        ans = max(ans, (int)((R + (LS > 0 ? (k - 2) * (uint64_t)LS % M : 0) + L) % M));
        return ans;
    }
};