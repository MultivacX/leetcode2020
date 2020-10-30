// 1366. Rank Teams by Votes
// https://leetcode.com/problems/rank-teams-by-votes/

// Runtime: 48 ms, faster than 19.33% of C++ online submissions for Rank Teams by Votes.
// Memory Usage: 18.4 MB, less than 5.02% of C++ online submissions for Rank Teams by Votes.

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int M = votes.size();
        const int N = votes[0].size();
        vector<bool> visited(26, false);
        vector<vector<int>> score(26, vector<int>(N + 1, 0));
        for (int j = 0; j < 26; ++j) score[j].back() = 26 - j;
        for (int i = 0; i < N; ++i) {
            for (auto v : votes) {
                int j = v[i] - 'A';
                visited[j] = true;
                ++score[j][i];
            }
        }
        sort(begin(score), end(score));
        string r;
        for (int j = 25; j >= 0 && visited[26 - score[j].back()]; --j) 
            r.push_back(26 - score[j].back() + 'A');
        return r;
    }
};