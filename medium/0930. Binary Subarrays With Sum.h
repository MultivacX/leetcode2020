// 930. Binary Subarrays With Sum

// Runtime: 20 ms, faster than 98.20% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Binary Subarrays With Sum.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;
        int sum = 0;
        int left = 0;
        int zero = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > S) {
                zero = 0;
                while (left <= i && sum > S) sum -= A[left++];
            } 
            if (sum == S && left <= i) {
                while (left < i && A[left] == 0) {
                    ++left;
                    ++zero;
                }
                ans += zero + 1;
            }
        }
        return ans;
    }
};