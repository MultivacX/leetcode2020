// 286. Walls and Gates
// https://leetcode.com/problems/walls-and-gates/

// Runtime: 44 ms, faster than 99.16% of C++ online submissions for Walls and Gates.
// Memory Usage: 14.5 MB, less than 91.46% of C++ online submissions for Walls and Gates.
    
class Solution {
    int M;
    int N;
    
    void move(vector<vector<int>>& rooms, int i, int j, int distance) {
        if (i < 0 || i >= M || j < 0 || j >= N) return;
        if (rooms[i][j] < 0) return;
        if (distance > 0 && rooms[i][j] <= distance) return;
        
        rooms[i][j] = distance;
        move(rooms, i - 1, j, distance + 1);
        move(rooms, i + 1, j, distance + 1);
        move(rooms, i, j - 1, distance + 1);
        move(rooms, i, j + 1, distance + 1);
    }
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        M = rooms.size();
        if (M == 0) return;
        N = rooms[0].size();
        if (N == 0) return;
        
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (rooms[i][j] == 0)
                    move(rooms, i, j, 0);
    }
};