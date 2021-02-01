// 296. Best Meeting Point
// https://leetcode.com/problems/best-meeting-point/

// Runtime: 8 ms, faster than 99.60% of C++ online submissions for Best Meeting Point.
// Memory Usage: 9 MB, less than 96.44% of C++ online submissions for Best Meeting Point.
    
class Solution {
    int getDistance(const int C, const vector<int>& xv) {
        int ans_x = INT_MAX;
        // xi ... xj ... xk
        // distance(i, j) = xi * (j - i) = -xi*i  +xi*j
        // distance(k, j) = xk * (k - j) =  xk*k  -xk*j
        int xi_i = 0, xi_j = 0, xk_k = 0, xk_j = 0;
        for (int j = 0; j < C; ++j) {
            // i = [0, j-1]
            // k = [j+1, C-1]
            if (j == 0) {
                xk_k = 0;
                for (int k = 1; k < C; ++k) {
                    xk_k += xv[k] * k;
                    xk_j += xv[k];
                }
                // cout << "to " << j << ": " << xk_k << endl;
                ans_x = min(ans_x, xk_k);
            } else if (j == C - 1) {
                xi_i = 0;
                for (int i = 0; i < C - 1; ++i) 
                    xi_i += xv[i] * (j - i);
                // cout << "to " << j << ": " << xi_i << endl;
                ans_x = min(ans_x, xi_i);
            } else {
                xi_i += xv[j - 1] * (j - 1);
                xi_j += xv[j - 1];
                
                xk_k -= xv[j] * j;
                xk_j -= xv[j];
                
                // cout << "to " << j << ": " << xi_j * j - xi_i + xk_k - xk_j * j << endl;
                ans_x = min(ans_x, xi_j * j - xi_i + xk_k - xk_j * j);
            }
        }
        return ans_x;
    }
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        const int R = grid.size();
        if (R == 0) return 0;
        const int C = grid[0].size();
        if (C == 0) return 0;
        
        vector<int> xv(C, 0);
        vector<int> yv(R, 0);
        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                if (grid[y][x] == 0) continue;
                ++xv[x];
                ++yv[y];
            }
        }
        return getDistance(C, xv) + getDistance(R, yv);
    }
};