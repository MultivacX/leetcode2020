// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Runtime: 112 ms, faster than 77.78% of C++ online submissions for Subarray Sums Divisible by K.
// Memory Usage: 30.3 MB, less than 73.24% of C++ online submissions for Subarray Sums Divisible by K.

// Time Complexity: O(N)O, where N is the length of A.
// Space Complexity: O(K).

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // prefix sum
        int S = A[0];
        
        // remainders
        vector<int> R(K, 0);
        R[(S % K + K) % K] = 1;
        
        for (int i = 1; i < A.size(); ++i) {
            S += A[i];
            ++R[(S % K + K) % K];
        }
        
        int ans = R[0];
        for (int r : R)
            ans += r * (r - 1) / 2;
        return ans;
    }
};