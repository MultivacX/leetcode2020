// 822. Card Flipping Game
// https://leetcode.com/problems/card-flipping-game/

// Runtime: 56 ms, faster than 29.05% of C++ online submissions for Card Flipping Game.
// Memory Usage: 19.7 MB, less than 30.30% of C++ online submissions for Card Flipping Game.

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < fronts.size(); ++i) {
            if (same.count(fronts[i]) == 0) ans = min(ans, fronts[i]);
            if (same.count(backs[i]) == 0) ans = min(ans, backs[i]);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};