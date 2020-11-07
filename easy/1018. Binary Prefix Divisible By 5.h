// 1018. Binary Prefix Divisible By 5
// https://leetcode.com/problems/binary-prefix-divisible-by-5/

// Runtime: 20 ms, faster than 71.65% of C++ online submissions for Binary Prefix Divisible By 5.
// Memory Usage: 14.3 MB, less than 100.00% of C++ online submissions for Binary Prefix Divisible By 5.

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        const int N = A.size();
        vector<bool> ans(N, false);
        for (int i = 0, v = 0; i < N; ++i) {
            v = (v * 2 + A[i]) % 10;
            ans[i] = v % 5 == 0;
        }
        return ans;
    }
};