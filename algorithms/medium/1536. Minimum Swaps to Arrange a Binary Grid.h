// 1536. Minimum Swaps to Arrange a Binary Grid
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

// Runtime: 132 ms, faster than 60.69% of C++ online submissions for Minimum Swaps to Arrange a Binary Grid.
// Memory Usage: 26.1 MB, less than 42.20% of C++ online submissions for Minimum Swaps to Arrange a Binary Grid.
    
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<int> zeros(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] == 1) break;
                ++zeros[i];
            }
        }
        
        // for (int i = 0; i < N; ++i) cout << i << ":" << zeros[i] << ", "; cout << endl; 
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            // min zeros at [i]
            int z = N - i - 1;
            if (zeros[i] >= z) continue;
            
            // find zeros[j] >= z
            int j = i + 1;
            while (j < N && zeros[j] < z) ++j;
            if (j >= N) return -1;
            
            // swap j to i
            while (j > i) {
                swap(zeros[j - 1], zeros[j]);
                --j;
                ++ans;
            }
        }
        return ans;
    }
};