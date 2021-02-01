// 396. Rotate Function

// Runtime: 8 ms, faster than 93.14% of C++ online submissions for Rotate Function.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Rotate Function.

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // F(k + 1) - F(k) = sum(A[i]) - n * A[i - (k + 1)]
        
        int64_t f = 0;
        int64_t s = 0;
        const int64_t n = A.size();
        for (int i = 0; i < n; ++i) {
            f += i * A[i];
            s += A[i];
        }
        int64_t ans = f;
        //cout << f << endl;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * A[n - i];
            //cout << f << endl;
            ans = max(ans, f);
        }
        return ans;
    }
};