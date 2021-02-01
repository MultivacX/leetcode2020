// 562. Longest Line of Consecutive One in Matrix
// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/

// Runtime: 188 ms, faster than 36.68% of C++ online submissions for Longest Line of Consecutive One in Matrix.
// Memory Usage: 28.6 MB, less than 48.47% of C++ online submissions for Longest Line of Consecutive One in Matrix.
    
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        // diagonals: key = {i-k, j-k}, k = min(i, j)
        // anti-diagonals: key = {i-k, j+k}, k = min(i, N-1-j)
        // vertical: key = j
        
        const int R = M.size();
        if (R == 0) return 0;
        const int C = M[0].size();
        if (C == 0) return 0;
        
        // key, last {i, j}
        unordered_map<int, int> v, d, a;
        int ans = 0;
        
        auto updateH = [&](int val, int& h){
            if (val == 0) h = 0;
            else ans = max(++h, ans);
        };
        
        auto updateV = [&](int i, int j){
            if (M[i][j] == 0) v[j] = 0;
            else ans = max(++v[j], ans);
        };
        
        auto updateD = [&](int i, int j){
            int k = min(i, j);
            int key = (i - k) * C + (j - k);
            if (M[i][j] == 0) d[key] = 0;
            else ans = max(++d[key], ans);
        };
        
        auto updateA = [&](int i, int j){
            int k = min(i, C - 1 - j);
            int key = (i - k) * C + (j + k);
            if (M[i][j] == 0) a[key] = 0;
            else ans = max(++a[key], ans);
        };
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0, h = 0; j < C; ++j) {
                updateH(M[i][j], h);
                updateV(i, j);
                updateD(i, j);
                updateA(i, j);
            }
        }
        return ans;
    }
};