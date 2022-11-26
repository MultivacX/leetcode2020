// 1926. Nearest Exit from Entrance in Maze
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

// Runtime: 151 ms, faster than 83.19% of C++ online submissions for Nearest Exit from Entrance in Maze.
// Memory Usage: 37.1 MB, less than 18.85% of C++ online submissions for Nearest Exit from Entrance in Maze.

static const int m2[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution
{
    bool enqueue(queue<vector<int>> &q, int i, int j, vector<vector<char>> &maze)
    {
        bool res = false;
        int m = maze.size(), n = maze[0].size();
        for (int x = 0; x < 4; ++x)
        {
            int ni = i + m2[x][0];
            int nj = j + m2[x][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            {
                res = true;
                continue;
            }
            if (maze[ni][nj] != '.')
                continue;
            maze[ni][nj] = '-';
            q.push(vector<int>{ni, nj});
        }
        return res;
    }

public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int i = entrance[0], j = entrance[1];
        maze[i][j] = '*';
        queue<vector<int>> q;
        enqueue(q, i, j, maze);
        if (q.empty())
            return -1;

        int steps = 1;
        while (!q.empty())
        {
            int n = q.size();
            for (int k = 0; k < n; ++k)
            {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();

                if (enqueue(q, i, j, maze))
                    return steps;
            }
            ++steps;
        }
        return -1;
    }
};