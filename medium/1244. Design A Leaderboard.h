// 1244. Design A Leaderboard
// https://leetcode.com/problems/design-a-leaderboard/

// Runtime: 16 ms, faster than 94.21% of C++ online submissions for Design A Leaderboard.
// Memory Usage: 11.9 MB, less than 28.97% of C++ online submissions for Design A Leaderboard.
    
class Leaderboard {
    // id, score
    unordered_map<int, int> players;
    // score, {id}
    map<int, unordered_set<int>> scores;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int oldScore = players[playerId];
        if (oldScore > 0) {
            scores[oldScore].erase(playerId);
            if (scores[oldScore].empty())
                scores.erase(oldScore);
        }
        score += oldScore;
        players[playerId] = score;
        scores[score].insert(playerId);
    }
    
    int top(int K) {
        // cout << K << endl;
        // for (auto it : scores) {
        //     cout << "  " << it.first << ": ";
        //     for (int id : it.second) cout << id << " ";
        //     cout << endl;
        // }
        int sum = 0;
        for (auto it = scores.crbegin(); K > 0 && it != scores.crend(); ++it) {
            int cnt = it->second.size();
            sum += min(K, cnt) * it->first;
            K -= cnt;
        }
        return sum;
    }
    
    void reset(int playerId) {
        if (players.count(playerId) == 0)
            return;
        
        int oldScore = players[playerId];
        players.erase(playerId);
        
        scores[oldScore].erase(playerId);
        if (scores[oldScore].empty())
            scores.erase(oldScore);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */