// 909. Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders/

// Runtime: 28 ms, faster than 88.96% of C++ online submissions for Snakes and Ladders.
// Memory Usage: 13.3 MB, less than 60.91% of C++ online submissions for Snakes and Ladders.

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int N = board.size();
        
        auto getK = [=](int r, int c){
            return 1 + (N - 1 - r) * N + (((N - r) & 1) ? c : (N - 1 - c));  
        };
        auto getRC = [=](int k, int& r, int& c){
            --k;
            r = N - 1 - k / N;
            c = ((N - r) & 1) ? k % N : N - 1 - k % N;
        };
        
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         int k, r, c;
        //         k = getK(i, j);
        //         getRC(k, r, c);
        //         printf("%d(%d:%d,%d:%d) ", k, i, r, j, c);
        //     }
        //     cout << endl;    
        // }
        
        vector<int> M(N * N + 1, INT_MAX);
        M[0] = M[1] = 0;
        int moves = 0;
        queue<int> q; q.push(1);
        while (!q.empty()) {
            ++moves;
            int size = q.size();
            while (size-- > 0) {
                int x = q.front(); q.pop();
                for (int i = x + 1; i <= x + 6 && i <= N * N; ++i) {
                    int k = i, r, c; getRC(k, r, c);
                    if (board[r][c] != -1) k = board[r][c];
                    if (M[k] <= moves) continue;
                    M[k] = moves;
                    q.push(k);
                }
            }
        }
        return M.back() == INT_MAX ? -1 : M.back();
    }
};