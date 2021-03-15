// 547. Friend Circles

// Runtime: 24 ms, faster than 49.05% of C++ online submissions for Friend Circles.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Friend Circles.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int N = M.size();
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (M[i][i] == 0) continue;
            ++ans;
            
            deque<int> q;
            q.push_back(i);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int k = q.front();
                    q.pop_front();
                    M[k][k] = 0;
                    
                    for (int j = 0; j < N; ++j) {
                        if (M[k][j] == 0) continue;
                        M[k][j] = 0;
                        M[j][k] = 0;
                        q.push_back(j);
                    }
                }
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isConnected[i][i] == 1) ++ans;
            else continue;
            
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int size = q.size();
                while (size-- > 0) {
                    int j = q.front(); q.pop();
                    isConnected[j][j] = 0;
                    
                    for (int k = 0; k < n; ++k) {
                        if (isConnected[j][k] != 1)
                            continue;
                        isConnected[j][k] = 0;
                        isConnected[k][j] = 0;
                        q.push(k);
                    }
                }
            }    
        }
        return ans;
    }
};