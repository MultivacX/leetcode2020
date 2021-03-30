// 1036. Escape a Large Maze
// https://leetcode.com/problems/escape-a-large-maze/

// Runtime: 316 ms, faster than 62.50% of C++ online submissions for Escape a Large Maze.
// Memory Usage: 61.9 MB, less than 62.50% of C++ online submissions for Escape a Large Maze.

class Solution {
    bool bfs(const unordered_set<int64_t>& blocked, 
             const vector<int>& source, 
             const vector<int>& target) {
        const int64_t n = 1000000;
        
        int si = source[0], sj = source[1];
        int ti = target[0], tj = target[1];
        int64_t sk = si * n + sj;

        int64_t level = 0;
        queue<int64_t> q;
        q.push(sk);
        unordered_set<int64_t> visited{sk};
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int64_t ck = q.front();
                q.pop();

                int ci = ck / n;
                int cj = ck % n;
                if (ci == ti && cj == tj)
                    return true;

                static const vector<int> d{0, 1, 0, -1, 0};
                for (int i = 0; i < 4; ++i) {
                    int ni = ci + d[i];
                    int nj = cj + d[i + 1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                        continue;

                    int64_t nk = ni * n + nj;
                    if (blocked.count(nk) || !visited.insert(nk).second)
                        continue;

                    q.push(nk);
                }
            }

            if (++level >= blocked.size())
            // manhattan_distance(source, target) = |ti - si| + |tj - sj|
            // if (++level >= blocked.size() * 2) 
                return true;
        }
        return false;
    }
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        const int64_t n = 1000000;
        
        unordered_set<int64_t> blocked_;
        for (const auto& b : blocked)
            blocked_.insert(b[0] * n + b[1]);
        
        return bfs(blocked_, source, target) && bfs(blocked_, target, source);
    }
};

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // blocked circle without/with boards
        // source & target both inside/outside circle
    }
};