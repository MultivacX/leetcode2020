// 1536. Minimum Swaps to Arrange a Binary Grid
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

// list ?
// 1 pos, min_idx after bubble pop

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();
        // vector<int> rows(N, -1);
        // {pos_1, cnt-1}
        list<pair<int, int>> l;
        unordered_map<int, int> m;
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    // rows[i] = j;
                    l.push_back({j, m[j]++});
                    break;
                }
            }
        }
        for (int k : rows) cout << k << " "; cout << endl; cout << endl;
        vector<int> sortedRows(rows);
        sort(begin(sortedRows), end(sortedRows));
        for (int i = 0; i < N; ++i) if (sortedRows[i] > i) return -1;
        
        int ans = 0;
        int i = 0;
        while (i < N) {
            if (rows[i] <= i) { ++i; continue; }
            
            int j = i;
            while (j + 1 < N) {
                if (rows[j] <= rows[j + 1]) ++j;
                else if (rows[j + 1] >= j + 1) ++j;
                else { 
                    swap(rows[j], rows[j + 1]); 
                    ++ans; 
                    for (int k : rows) cout << k << " "; cout << endl;
                    break; 
                }
            }
        }
        
         cout << endl; for (int k : rows) cout << k << " "; cout << endl;
        return ans;
    }
};
