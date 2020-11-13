// 1626. Best Team With No Conflicts
// https://leetcode.com/problems/best-team-with-no-conflicts/

// Runtime: 448 ms, faster than 12.42% of C++ online submissions for Best Team With No Conflicts.
// Memory Usage: 21.7 MB, less than 24.32% of C++ online submissions for Best Team With No Conflicts.

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int N = scores.size();
        
        vector<vector<int>> v(N, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            v[i][0] = ages[i];
            v[i][1] = scores[i];
            v[i][2] = scores[i];
        }
        sort(begin(v), end(v));
        
        int ans = v[0][2];
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[i][0] == v[j][0] || v[i][1] >= v[j][1]) 
                    v[i][2] = max(v[i][2], v[j][2] + v[i][1]);
            }
            if (v[i][2] > ans) ans = v[i][2];
        }
        return ans;
    }
};