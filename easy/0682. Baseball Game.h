// 682. Baseball Game
// https://leetcode.com/problems/baseball-game/

// Runtime: 8 ms, faster than 48.15% of C++ online submissions for Baseball Game.
// Memory Usage: 8.7 MB, less than 82.61% of C++ online submissions for Baseball Game.
    
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (const auto& s : ops) {
            const int N = scores.size();
            if (s[0] == '+') scores.push_back(scores[N - 2] + scores[N - 1]);
            else if (s[0] == 'D') scores.push_back(scores[N - 1] * 2);
            else if (s[0] == 'C') scores.pop_back();
            else scores.push_back(stoi(s));
        }
        return accumulate(begin(scores), end(scores), 0);
    }
};