// 51. N-Queens

// Runtime: 48 ms, faster than 12.77% of C++ online submissions for N-Queens.
// Memory Usage: 17.9 MB, less than 6.25% of C++ online submissions for N-Queens.

class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<string> visited;
    
    vector<vector<string>> solveNQueens(int n) {
        for (int j = 0; j < n / 2; ++j) {
            vector<int> indexes{j};
            solve(n, indexes, 1);
        }
        if (n % 2) {
            vector<int> indexes{n / 2};
            solve(n, indexes, 1);
        }
        return ans;
    }
    
    void solve(int n, vector<int>& indexes, int row) {
        if (row >= n) {
            vector<string> s(n, string(n, '.'));
            vector<string> t(n, string(n, '.'));
            string ss;
            string tt;
            for (int i = 0; i < n; ++i) {
                s[i][indexes[i]] = 'Q';
                t[i][n - 1 - indexes[i]] = 'Q';
                ss += s[i];
                tt += t[i];
            }
            if (visited.count(ss) == 0) {
                ans.push_back(s);
                visited.insert(ss);
            }
            if (visited.count(tt) == 0) {
                ans.push_back(t);
                visited.insert(tt);
            }
            return;
        }
        
        unordered_set<int> occupied_cols;
        for (int i = 0; i < row; ++i) {
            occupied_cols.insert(indexes[i]);
            occupied_cols.insert(indexes[i] - (row - i));
            occupied_cols.insert(indexes[i] + (row - i));
        }
        for (int j = 0; j < n; ++j) {
            if (occupied_cols.count(j)) continue;
            indexes.push_back(j);
            solve(n, indexes, row + 1);
            indexes.pop_back();
        }
    }
};