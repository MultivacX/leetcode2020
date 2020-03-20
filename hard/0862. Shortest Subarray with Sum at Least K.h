// 862. Shortest Subarray with Sum at Least K

// Time Limit Exceeded
// 85 / 93 test cases passed.
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A[0] >= K) return 1;
        
        int len = A.size() + 1;
        int i = 0;
        int sum = A[0];
        for (int j = 1; j < A.size(); ++j) {
            if (A[j] >= K) return 1;
            
            sum += A[j];
            if (sum <= A[j]) {
                i = j;
                sum = A[j];
            } else if (sum >= K) {
                int tmp = 0;
                for (int k = j; k >= i; --k) {
                    tmp += A[k];
                    if (tmp >= K) {
                        len = min(len, j - k + 1);
                        i = k;
                        sum = tmp;
                        break;
                    }
                }
            }
        }
        return len == A.size() + 1 ? -1 : len;
    }
};