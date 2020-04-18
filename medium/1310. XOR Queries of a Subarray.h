// 1310. XOR Queries of a Subarray

// Runtime: 156 ms, faster than 28.08% of C++ online submissions for XOR Queries of a Subarray.
// Memory Usage: 23.3 MB, less than 100.00% of C++ online submissions for XOR Queries of a Subarray.

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int M = arr.size();
        const int N = queries.size();
        // arr[i] means XOR from 0 to i, [0, i]
        // arr[L - 1] XOR arr[R] means XOR from L to R, [L, R]
        for (int i = 1; i < M; ++i) arr[i] ^= arr[i - 1];
        vector<int> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            int L = queries[i][0];
            int R = queries[i][1];
            if (L == 0) {
                ans[i] = arr[R];
            } else {
                ans[i] = arr[R] ^ arr[L - 1];
            }
        }
        return ans;
    }
};