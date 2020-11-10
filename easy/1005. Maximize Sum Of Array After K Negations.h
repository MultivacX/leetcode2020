// 1005. Maximize Sum Of Array After K Negations
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// Runtime: 4 ms, faster than 99.86% of C++ online submissions for Maximize Sum Of Array After K Negations.
// Memory Usage: 9.4 MB, less than 10.09% of C++ online submissions for Maximize Sum Of Array After K Negations.

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int sum = 0;
        int i = 0;
        while (i < A.size()) {
            if (K <= 0) { 
                sum += A[i++]; 
            } else if (A[i] == 0) { 
                K = 0; 
                ++i; 
            } else if (i + 1 == A.size() || 
                       A[i] > 0 || 
                       -A[i] < A[i + 1]) { 
                sum += A[i++] * ((K & 1) ? -1 : 1); 
                K = 0; 
            } else { 
                sum -= A[i++]; 
                --K;
            }
        }
        return sum;
    }
};