// 962. Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp/

// Runtime: 892 ms, faster than 5.04% of C++ online submissions for Maximum Width Ramp.
// Memory Usage: 44.6 MB, less than 6.38% of C++ online submissions for Maximum Width Ramp.

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        const int N = A.size();
        vector<vector<int>> B(N, vector<int>(2));
        for (int i = 0; i < N; ++i) {
            B[i][0] = A[i];
            B[i][1] = i;
        }
        
        sort(begin(B), end(B));
        
        int ans = 0;
        for (int k = 1, i = B[0][1]; k < N; ++k) {
            int j = B[k][1];
            if (i < j) ans = max(ans, j - i);
            i = min(i, j);
        }
        return ans;
    }
};