// 1588. Sum of All Odd Length Subarrays
// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

// Runtime: 4 ms, faster than 77.57% of C++ online submissions for Sum of All Odd Length Subarrays.
// Memory Usage: 8.5 MB, less than 99.40% of C++ online submissions for Sum of All Odd Length Subarrays.
    
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        const int N = arr.size();
        vector<int> sums(N);
        for (int i = 0, s = 0; i < N; ++i) {
            s += arr[i];
            sums[i] = s;
        }
        int ans = 0;
        for (int l = 1; l <= N; l += 2) {
            for (int i = 0, s = sums[l - 1]; i + l <= N; ++i) {
                ans += s;
                if (i + l < N) s = s - arr[i] + arr[i + l];
            }
        }
        return ans;
    }
};