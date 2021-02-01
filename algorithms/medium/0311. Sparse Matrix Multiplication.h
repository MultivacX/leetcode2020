// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

// Runtime: 8 ms, faster than 75.62% of C++ online submissions for Sparse Matrix Multiplication.
// Memory Usage: 8.9 MB, less than 5.69% of C++ online submissions for Sparse Matrix Multiplication.
    
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int ra = A.size();
        const int ca = A[0].size();
        const int rb = B.size();
        const int cb = B[0].size();
        
        unordered_map<int, vector<pair<int, int>>> a, b;
        for (int i = 0; i < ra; ++i) {
            for (int j = 0; j < ca; ++j) {
                if (A[i][j] == 0) continue;
                a[i].push_back({j, A[i][j]});
            }
        }
        for (int j = 0; j < cb; ++j) {
            for (int i = 0; i < rb; ++i) {
                if (B[i][j] == 0) continue;
                b[j].push_back({i, B[i][j]});
            }
        }
        
        vector<vector<int>> C(ra, vector<int>(cb, 0));
        // C[i][j] = A[i][x] * B[x][j]
        for (int i = 0; i < ra; ++i) {
            for (int j = 0; j < cb; ++j) {
                if (a.count(i) == 0 || b.count(j) == 0)
                    continue;
                int ai = 0, bj = 0;
                while (ai < a[i].size() && bj < b[j].size()) {
                    if (a[i][ai].first == b[j][bj].first)
                        C[i][j] += a[i][ai++].second * b[j][bj++].second;
                    else if (a[i][ai].first < b[j][bj].first) ++ai;
                    else ++bj;
                }
            }
        }
        return C;
    }
};