// 1311. Get Watched Videos by Your Friends
// https://leetcode.com/problems/get-watched-videos-by-your-friends/

// Runtime: 328 ms, faster than 5.60% of C++ online submissions for Get Watched Videos by Your Friends.
// Memory Usage: 35.5 MB, less than 95.26% of C++ online submissions for Get Watched Videos by Your Friends.

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int N = watchedVideos.size();
        // vector<vector<bool>> g(N, vector<bool>(N, false));
        // for (int i = 0; i < N; ++i) 
        //     for (int j : friends[i])
        //         g[i][j] = true;
        
        queue<int> q; q.push(id);
        vector<bool> visited(N, false);
        visited[id] = true;
        while (level-- > 0) {
            int size = q.size();
            while (size-- > 0) {
                int i = q.front(); q.pop();
                
                for (int j : friends[i])
                    if (!visited[j])
                        visited[j] = true, q.push(j);
            }
        }
        
        unordered_map<string, int> m;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (string v : watchedVideos[i])
                ++m[v];
        }
        
        vector<string> ans;
        for (auto it : m) ans.push_back(it.first);
        sort(begin(ans), end(ans), [&](string& l, string& r){
            return m[l] < m[r] || (m[l] == m[r] && l < r);
        });
        return ans;
    }
};