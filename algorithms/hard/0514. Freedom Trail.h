// 514. Freedom Trail

// Time Limit Exceeded
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // [c - 'a'] = {idx}
        vector<vector<int>> characters(26, vector<int>());
        for (int i = 0; i < ring.length(); ++i)
            characters[ring[i] - 'a'].push_back(i);
        return dfs(ring.length(), characters, key, 0, 0);
    }
    
    int dfs(const int N, const vector<vector<int>>& characters, const string& key, int k, int rotation) {
        if (k >= key.length()) return 0;
        
        int steps = N;
        for (int i : characters[key[k] - 'a']) {
            int r = (i + rotation + N) % N;
            if (N - r >= r) steps = min(steps, r + dfs(N, characters, key, k + 1, (rotation - r + N) % N));
            else steps = min(steps, N - r + dfs(N, characters, key, k + 1, (rotation + N - r) % N));
        }
        return steps + 1/*push button*/;
    }
};