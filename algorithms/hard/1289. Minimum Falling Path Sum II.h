// 1289. Minimum Falling Path Sum II

// Runtime: 64 ms, faster than 66.84% of C++ online submissions for Minimum Falling Path Sum II.
// Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions for Minimum Falling Path Sum II.

// Time Complexity: O(N * N).
// Space Complexity: O(N).

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        const int N = arr.size();
        if (N == 1) return arr[0][0];
        
        vector<int> dp(arr[0]);
        for (int i = 1; i < N; ++i) {
            auto idxs = get_min_idxs(dp);
            int v0 = dp[idxs[0]];
            int v1 = dp[idxs[1]];
            // printf("[%d]:%d, [%d]:%d\n", idxs[0], v0, idxs[1], v1);
            for (int j = 0; j < N; ++j) {
                dp[j] = arr[i][j] + (j != idxs[0] ? v0 : v1);
            }
        }
        return *min_element(begin(dp), end(dp));
    }
    
    array<int, 2> get_min_idxs(const vector<int>& row) {
        // for (int j = 0; j < row.size(); ++j) cout << row[j] << " "; cout << endl;
        int a = -1, b = -1;
        for (int j = 0; j < row.size(); ++j) if (a < 0 || row[j] <= row[a]) a = j;
        for (int j = 0; j < row.size(); ++j) if ((b < 0 || row[j] <= row[b]) && j != a) b = j;
        return {a, b};
    }
};