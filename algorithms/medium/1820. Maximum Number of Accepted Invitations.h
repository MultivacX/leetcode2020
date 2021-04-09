// 1820. Maximum Number of Accepted Invitations
// https://leetcode.com/problems/maximum-number-of-accepted-invitations/

// Runtime: 172 ms, faster than 100.00% of C++ online submissions for Maximum Number of Accepted Invitations.
// Memory Usage: 37.4 MB, less than 100.00% of C++ online submissions for Maximum Number of Accepted Invitations.
    
class Solution {
    int m;
    int n;
    vector<int> girls;
    
    bool check(const vector<vector<int>>& grid, int i, vector<bool>& visited) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) continue;
            if (visited[j]) continue;
            visited[j] = true;
            
            if (girls[j] == -1 || check(grid, girls[j], visited)) {
                girls[j] = i;
                return true;
            }
        }
        return false;
    }
    
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        girls = vector<int>(n, -1);
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<bool> visited(n, false);
            if (check(grid, i, visited)) 
                ++ans;
        }
        return ans;
    }
};