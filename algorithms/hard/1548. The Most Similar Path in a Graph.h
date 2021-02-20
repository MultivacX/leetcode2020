// 1548. The Most Similar Path in a Graph
// https://leetcode.com/problems/the-most-similar-path-in-a-graph/

// Runtime: 1708 ms, faster than 5.01% of C++ online submissions for The Most Similar Path in a Graph.
// Memory Usage: 95.9 MB, less than 91.54% of C++ online submissions for The Most Similar Path in a Graph.
    
class Solution {
    int m;
    int n;
    vector<vector<int>> graph;
    vector<vector<int>> memo;
    int minDistance;
    vector<int> ans;
    
    void findPath(const vector<string>& names, 
                  const vector<string>& targetPath,
                  vector<int>& path,
                  int distance) {
        if (minDistance < distance) return;
        if (path.size() == m) { minDistance = distance; ans = path; return; }
        
        if (path.empty()) {
            for (int i = 0; i < n; ++i) {
                path.push_back(i);
                int d = names[i] == targetPath[0] ? 0 : 1;
                findPath(names, targetPath, path, distance + d);
                path.pop_back();
            }
        } else {
            int j = path.back();
            int k = path.size();
            for (int i : graph[j]) {
                int d = distance + (names[i] == targetPath[k] ? 0 : 1);
                if (d >= memo[i][k]) continue;
                memo[i][k] = d;
                path.push_back(i);
                findPath(names, targetPath, path, d);
                path.pop_back();
            }
        }
    }
    
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        this->m = targetPath.size();
        this->n = n;
        this->graph = vector<vector<int>>(n);
        for (const auto& r : roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }
        this->memo = vector<vector<int>>(n, vector<int>(m + 1, m + 1));
        for (int i = 0; i < n; ++i) memo[i][0] = 0;
        this->minDistance = this->m;
        
        vector<int> path;
        findPath(names, targetPath, path, 0);
        return ans;
    }
};


// TLE
// 258 / 258 test cases passed, but took too long.
class Solution {
    int m;
    int n;
    vector<vector<bool>> graph;
    vector<vector<int>> memo;
    int minDistance;
    vector<int> ans;
    
    void findPath(const vector<string>& names, 
                  const vector<string>& targetPath,
                  vector<int>& path,
                  int distance) {
        if (minDistance < distance) return;
        if (path.size() == m) { minDistance = distance; ans = path; return; }
        
        if (path.empty()) {
            for (int i = 0; i < n; ++i) {
                path.push_back(i);
                int d = names[i] == targetPath[0] ? 0 : 1;
                findPath(names, targetPath, path, distance + d);
                path.pop_back();
            }
        } else {
            int j = path.back();
            int k = path.size();
            for (int i = 0; i < n; ++i) {
                if (!graph[j][i]) continue;
                int d = distance + (names[i] == targetPath[k] ? 0 : 1);
                if (d >= memo[i][k]) continue;
                memo[i][k] = d;
                path.push_back(i);
                findPath(names, targetPath, path, d);
                path.pop_back();
            }
        }
    }
    
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        this->m = targetPath.size();
        this->n = n;
        this->graph = vector<vector<bool>>(n, vector<bool>(n, false));
        for (const auto& r : roads) graph[r[0]][r[1]] = graph[r[1]][r[0]] = true;
        this->memo = vector<vector<int>>(n, vector<int>(m + 1, m + 1));
        for (int i = 0; i < n; ++i) memo[i][0] = 0;
        this->minDistance = this->m;
        
        vector<int> path;
        findPath(names, targetPath, path, 0);
        return ans;
    }
};