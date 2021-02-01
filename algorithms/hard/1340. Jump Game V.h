// 1340. Jump Game V

// Runtime: 56 ms, faster than 38.85% of C++ online submissions for Jump Game V.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Jump Game V.

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        const int N = arr.size();
        if (N == 1) return 1;
        
        vector<int> idx(N, 0);
        for (int i = 1; i < N; ++i) 
            idx[i] = i;
        sort(begin(idx), end(idx), [&arr](int l, int r){ return arr[l] < arr[r]; });
        
        // for (int k = 0; k < N; ++k) {
        //     int i = idx[k];
        //     cout << "[" << i << "]:" << arr[i] << " ";
        // }
        // cout << endl;
        
        int ans = 0;
        vector<int> dp(N, 1);
        for (int k = 1; k < N; ++k) {
            int i = idx[k];
            int cnt = 0;
            for (int j = i - 1; j >= max(0, i - d); --j) {
                if (arr[j] >= arr[i]) break;
                cnt = max(cnt, dp[j]);
            }
            for (int j = i + 1; j <= min(N - 1, i + d); ++j) {
                if (arr[j] >= arr[i]) break;
                cnt = max(cnt, dp[j]);
            }
            dp[i] = max(dp[i], 1 + cnt);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};